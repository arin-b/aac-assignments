#include <stdio.h>

int sum_iterative(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
        sum = sum + i;

    return sum;
}

int sum_recursive(int n)
{
    if (n == 0)
        return 0;

    return n + sum_recursive(n - 1);
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0)
        printf("Please enter a non-negative number.\n");
    else
    {
        printf("Sum using iterative method: %d\n", sum_iterative(n));
        printf("Sum using recursive method: %d\n", sum_recursive(n));
    }

    return 0;
}
