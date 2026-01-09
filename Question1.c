#include <stdio.h>

struct F {
    int p;
    int e;
};

int main() {
    int n, c = 0;
    scanf("%d", &n);

    struct F a[100];

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a[c].p = i;
            a[c].e = 0;
            while (n % i == 0) {
                a[c].e++;
                n /= i;
            }
            c++;
        }
    }

    if (n > 1) {
        a[c].p = n;
        a[c].e = 1;
        c++;
    }

    for (int i = 0; i < c; i++) {
        if (i > 0) printf(" * ");
        printf("%d^%d", a[i].p, a[i].e);
    }
    printf("\n");

    return 0;
}

/*
Time Complexity: O(sqrt(n))
   - The for loop runs from i=2 to sqrt(n)
   - The while loop divides n, total log(n) divisions
   - Overall: O(sqrt(n))
*/
