#include <stdio.h>
int searchBlock(int arr[], int x, int first, int last, int nblocks)
{
    // base case
    if (first > last)
    {
        return -1;
    }

    int len = (last - first) / nblocks;
    if (len == 0)
    {
        len = 1;
    }
    for (int i = 0; i < nblocks; i++)
    {
        int next_index = first + (i + 1) * len;
        if (next_index > last)
        {
            next_index = last;
        }
        if ((arr[first + i * len] <= x) && (x <= arr[first + (i + 1) * len]))
        {
            return searchBlock(arr, x, first + i * len, next_index, nblocks);
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 7;
    int nblocks = 3;
    int result = searchBlock(arr, x, 0, n - 1, nblocks);
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found in array\n");
    return 0;
}