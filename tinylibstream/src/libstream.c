#include "../include/libstream.h"

#include <stdlib.h>
#include <string.h>

struct stream *lbs_fopen(const char *path, const char *mode)
{
    int fd;
    if (!strcmp(mode, "r"))
        fd = open(path, O_RDONLY);
    else if (!strcmp(mode, "r+"))
        fd = open(path, O_RDWR);
    else if (!strcmp(mode, "w"))
        fd = open(path, O_WRONLY | O_CREAT | O_TRUNC);

    else if (!strcmp(mode, "w+"))
        fd = open(path, O_RDWR | O_CREAT | O_TRUNC);
    else
        return NULL;
    if (!fd)
        return NULL;
    return lbs_fdopen(fd, mode);
}

struct stream *lbs_fdopen(int fd, const char *mode)
{
    if (fd < 0)
        return NULL;
    struct stream *stream = malloc(sizeof(struct stream));

    if (!strcmp(mode, "r"))
        stream->flags = O_RDONLY;

    else if (!strcmp(mode, "r+"))
        stream->flags = O_RDWR;

    else if (!strcmp(mode, "w"))
        stream->flags = O_WRONLY | O_CREAT | O_TRUNC;

    else if (!strcmp(mode, "w+"))
        stream->flags = O_RDWR | O_CREAT | O_TRUNC;

    else
    {
        free(stream);
        return NULL;
    }

    stream->error = 0;
    stream->fd = fd;
    stream->buffering_mode = STREAM_BUFFERED;
    stream->io_operation = STREAM_READING;
    if (isatty(fd))
        stream->buffering_mode = STREAM_LINE_BUFFERED;
    stream->buffered_size = 0;
    stream->already_read = 0;

    return stream;
}

/*
** Closes the stream and underlying file descriptor, flushing buffered data.
** No other function should be called on the stream after lbs_fclose(), as
** the stream is freed if the function returns successfully.
** Works just like fclose(3).
*/
int lbs_fclose(struct stream *file)
{
    if (file)
    {
        lbs_fflush(file);
        close(file->fd);
        free(file);
        return 0;
    }
    return -1;
}

/*
** Writes a single character to some stream.
** It may cause the stream to flush if the buffer is full or the current
** buffering policy requires it.
** Works just like fputc(3). May set the error indicator.
*/
int lbs_fputc(int c, struct stream *stream)
{
    if (!stream)
        return -1;
    if (!stream_writable(stream))
        return -1;
    if (stream->io_operation == STREAM_READING)
    {
        lbs_fflush(stream);
        stream->io_operation = STREAM_WRITING;
    }
    stream->buffer[stream->buffered_size++] = c;
    if (stream->buffering_mode == STREAM_UNBUFFERED)
        lbs_fflush(stream);
    else if (stream->buffering_mode == STREAM_LINE_BUFFERED)
    {
        if (c == '\n')
            lbs_fflush(stream);
    }
    if (stream->buffered_size == LBS_BUFFER_SIZE)
        lbs_fflush(stream);
    return c;
}

/*
** Reads a new character from the stream's buffer.
** If the buffer it empty, it should be refilled.
** Works just like fgetc(3). May set the error indicator.
*/
int lbs_fgetc(struct stream *stream)
{
    if (!stream)
        return -1;
    if (!stream_readable(stream))
        return -1;
    if (stream->io_operation != STREAM_READING)
    {
        lbs_fflush(stream);
        stream->io_operation = STREAM_READING;
    }
    if (!stream->buffered_size || stream->already_read == stream->buffered_size)
    {
        lbs_fflush(stream);
        ssize_t nread = read(stream->fd, stream->buffer, LBS_BUFFER_SIZE);
        if (!nread)
            return LBS_EOF;
        stream->buffered_size = nread;
    }
    unsigned char c = stream->buffer[stream->already_read++];
    return c;
}

/*
** Flushes the stream's buffer to the underlying file descriptor, making sure
** the stream position is correct. When there is some write data buffered, it
** has to be written. When there is some read data buffered, it has to be
** discarded and the process must seek the file descriptor back to the
** position the user expects.
*/
int lbs_fflush(struct stream *stream)
{
    if (!stream)
        return -1;
    if (stream->io_operation == STREAM_WRITING)
    {
        if (stream->buffered_size > 0)
        {
            write(stream->fd, stream->buffer, stream->buffered_size);
            stream->buffered_size = 0;
        }
    }
    else
    {
        if (stream->buffered_size != stream->already_read)
            lseek(stream->fd, -stream_remaining_buffered(stream), SEEK_CUR);
        stream->buffered_size = 0;
        stream->already_read = 0;
    }
    return 0;
}
