#define _DEFAULT_SOURCE

#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static int run = 1;

void handler(int signum)
{
    static int nbsignal = 0;
    static int generation = 0;
    if (signum == SIGINT)
        run = 0;
    if (signum == SIGUSR1)
    {
        printf("Received %d signals.\n", ++nbsignal);
        fflush(stdout);
    }
    if (signum == SIGUSR2)
    {
        nbsignal++;
        printf("Current generation: %d\n", generation);
        fflush(stdout);
    }
    if (signum == SIGTERM)
    {
        generation++;
        nbsignal = 0;
        pid_t newpid = fork();
        if (!newpid)
            return;
        exit(0);
    }
}

int main(void)
{
    struct sigaction sa;
    sa.sa_flags = 0; // Nothing special to do
    sa.sa_handler = handler;
    // Initialize mask
    if (sigemptyset(&sa.sa_mask) < 0 || sigaction(SIGINT, &sa, NULL) < 0
        || sigaction(SIGUSR1, &sa, NULL) < 0
        || sigaction(SIGUSR2, &sa, NULL) < 0
        || sigaction(SIGTERM, &sa, NULL) < 0)
    {
        return -1;
    }
    pid_t pid = fork();

    if (pid < 0)
        return -1;

    if (pid == 0)
        while (run)
            ;
    else
        exit(0);

    return 0;
}
