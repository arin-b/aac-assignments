#include <stdio.h>

int is_prime(int n)
{
    if (n < 2)
        return 0;

    int i = 2;

    while (i * i <= n)
    {
        if (n % i == 0)
            return 0;

        i = i + 1;
    }

    return 1;
}

int nth_prime_iterative(int n)
{
    int count = 0;
    int number = 1;

    while (count < n)
    {
        number = number + 1;

        if (is_prime(number) == 1)
            count = count + 1;
    }

    return number;
}

int nth_prime_recursive(int n, int number, int count)
{
    number = number + 1;

    if (is_prime(number) == 1)
        count = count + 1;

    if (count == n)
        return number;

    return nth_prime_recursive(n, number, count);
}

int main()
{
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    if (n <= 0)
        printf("Please enter a positive number.\n");
    else
    {
        printf("Nth prime number using iterative method: %d\n",
               nth_prime_iterative(n));

        printf("Nth prime number using recursive method: %d\n",
               nth_prime_recursive(n, 1, 0));
    }

    return 0;
}
