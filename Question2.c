#include <stdio.h>

int search(int a[], int x, int l, int r, int k) {
    if (l == r)
        return a[l] == x ? l : -1;

    if (l + 1 == r) {
        if (a[l] == x) return l;
        if (a[r] == x) return r;
        return -1;
    }

    int len = (r - l) / k;
    if (len == 0) len = 1;

    for (int i = 0; i < k; i++) {
        int s = l + i * len;
        int e = l + (i + 1) * len;
        if (e > r) e = r;
        if (a[s] <= x && x <= a[e])
            return search(a, x, s, e, k);
    }

    return -1;
}

int main() {
    int n, x, k;
    scanf("%d", &n);

    int a[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d %d", &x, &k);

    int p = search(a, x, 0, n - 1, k);

    if (p == -1)
        printf("Not found\n");
    else
        printf("Found at index %d\n", p);

    return 0;
}

/*
Time Complexity: O(k * log_k(n))
   - Each level checks up to k blocks
   - Depth of recursion is log_k(n)

Binary Search: O(log n)
   - Divides into 2, checks 1

Comparison: Binary Search is faster when k > 2
*/
