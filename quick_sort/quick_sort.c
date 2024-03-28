void rec_quick_sort(int *tab, int begin, int end)
{
    if (begin >= end)
        return;
    else
    {
        int pos_pivot = (begin + end) / 2;
        int pivot = tab[pos_pivot];
        tab[pos_pivot] = tab[end];
        tab[end] = pivot;
        int next_swap = begin;
        for (int i = begin; i < end; i++)
        {
            if (tab[i] < pivot)
            {
                int tmp = tab[i];
                tab[i] = tab[next_swap];
                tab[next_swap] = tmp;
                next_swap++;
            }
        }
        tab[end] = tab[next_swap];
        tab[next_swap] = pivot;
        rec_quick_sort(tab, begin, next_swap - 1);
        rec_quick_sort(tab, next_swap + 1, end);
        return;
    }
}

void quicksort(int *tab, int len)
{
    rec_quick_sort(tab, 0, len - 1);
}
