#include <stdio.h>

int searchBlock(int arr[], int x, int first, int last, int nblocks) {
    if (first == last) {
        if (arr[first] == x)
            return first;
        return -1;
    }

    if (first + 1 == last) {
        if (arr[first] == x)
            return first;
        if (arr[last] == x)
            return last;
        return -1;
    }

    int len = (last - first) / nblocks;
    if (len == 0)
        len = 1;

    for (int i = 0; i < nblocks; i++) {
        int start = first + i * len;
        int end = first + (i + 1) * len;
        if (end > last)
            end = last;
        if ((arr[start] <= x) && (x <= arr[end])) {
            return searchBlock(arr, x, start, end, nblocks);
        }
    }

    return -1;
}

int main() {
    int n, x, nblocks;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &x);
    scanf("%d", &nblocks);

    int pos = searchBlock(arr, x, 0, n - 1, nblocks);

    if (pos == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", pos);

    return 0;
}

/*
Time Complexity: O(nblocks * log_nblocks(n))
   - At each level, we check up to nblocks blocks
   - The depth of recursion is log_nblocks(n)
   - Total: O(nblocks * log_nblocks(n))

Binary Search Complexity: O(log2(n))
   - Binary search divides array into 2 blocks
   - Checks only 1 block per level

Comparison:
   - Binary Search is faster when nblocks > 2
   - Block Search with nblocks=2 equals Binary Search
   - Block Search is slower because it checks more blocks per level
   - Binary Search: O(log n), Block Search: O(nblocks * log_nblocks(n))
   - For nblocks > 2: nblocks * log_nblocks(n) > log2(n)
*/
