int aux(const int vec[], int start, int end, int elt)
{
    int pivot_pos = end - start / 2;
    int pivot = vec[pivot_pos];
    if (start > end)
        return -1;
    if (elt < pivot)
    {
        return aux(vec, start, pivot_pos - 1, elt);
    }
    else if (elt > pivot)
    {
        return aux(vec, pivot_pos + 1, end, elt);
    }
    else
    {
        return pivot_pos;
    }
}

int binary_search(const int vec[], int size, int elt)
{
    return aux(vec, 0, size - 1, elt);
}
