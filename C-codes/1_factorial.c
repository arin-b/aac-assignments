#include <stdio.h>

long long factorial_iterative(int n)
{
    long long result = 1;

    for (int i = 1; i <= n; i++)
        result = result * i;

    return result;
}

long long factorial_recursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorial_recursive(n - 1);
}

int main()
{
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
    {
        printf("Factorial using iterative method: %lld\n",
               factorial_iterative(n));

        printf("Factorial using recursive method: %lld\n",
               factorial_recursive(n));
    }

    return 0;
}
