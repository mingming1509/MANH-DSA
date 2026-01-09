/*
int this problem, we study prime factorization, where a prositive interger is decomposed into a product of prime numbers raised to their respective powers
for example:
360 = 2^3 * 3 ^2 * 5^1

your task are:
-Prospose a*/

#include <stdio.h>

typedef struct
{
    int prime;
    int power;
} PrimeFactor;

void initPrimeFactor(PrimeFactor *pf, int prime, int power)
{
    pf->prime = prime;
    pf->power = power;
}

int isprime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
} // O(n^0.5)
void primefactorization(int n)
{
    PrimeFactor factors[100];
    int count = 0;

    for (int i = 2; i <= n; i++) // O(n)
    {
        if (isprime(i))
        {
            int power = 0;
            while (n % i == 0) // O(log n)
            {
                n /= i;
                power++;
            }
            if (power > 0)
            {
                initPrimeFactor(&factors[count], i, power);
                count++;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("%d^%d", factors[i].prime, factors[i].power);
        if (i < count - 1)
            printf(" * ");
    }
    printf("\n");
}
int main()
{
    PrimeFactor pf;

    int n = 360;
    printf("PrimeFactor of %d is: ", n);
    primefactorization(n);
    return 0;
}
