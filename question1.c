#include <stdio.h>

void div_func(int *q, int *r, int a, int b) {
    if (a < b) {
        *r = a;
    } else {
        *q = *q + 1;
        div_func(q, r, a - b, b);
    }
}

int main() {
    int a, b;
    printf("Enter dividend (a): ");
    scanf("%d", &a);
    printf("Enter divisor (b): ");
    scanf("%d", &b);

    // Initialize quotient and remainder to 0
    int quotient = 0;
    int remainder = 0;

    div_func(&quotient, &remainder, a, b);

    printf("Quotient: %d\n", quotient);
    printf("Remainder: %d\n", remainder);

    return 0;
}
