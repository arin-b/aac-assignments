#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    int maximum = arr[0];
    int i = 1;

    while (i < n)
    {
        if (arr[i] > maximum)
            maximum = arr[i];

        i = i + 1;
    }

    printf("Maximum number: %d\n", maximum);

    return 0;
}
