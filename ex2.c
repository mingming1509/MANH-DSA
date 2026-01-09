/*
 */
int searchBlock(int arr[], int x, int first, int last, int nblocks)
{

    int len = (last - first) / nblocks;
    if (len == 0)
    {
        len = 1;
    }
    for (int i = 0; i < nblocks; i++)
    {
        if ((arr[first + i * len] <= x) && (x <= arr[first + (i + 1) * len]))
        {
            return searchBlock(arr, x, first + i * len, first + (i + 1), nblocks);
        }
    }
}