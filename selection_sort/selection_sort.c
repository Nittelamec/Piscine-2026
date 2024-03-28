unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    int min = arr[start];
    unsigned int pos_min = start;
    for (unsigned int i = start + 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            pos_min = i;
        }
    };
    return pos_min;
}

void selection_sort(int arr[], unsigned size)
{
    if (size == 0)
    {
        return;
    }
    for (unsigned int i = 0; i < size; i++)
    {
        unsigned pos_min = array_min(arr, i, size);
        int tmp = arr[i];
        arr[i] = arr[pos_min];
        arr[pos_min] = tmp;
    }
    return;
}
