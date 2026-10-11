#include <stdio.h>

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n], ascending[n], descending[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);

        ascending[i] = arr[i];
        descending[i] = arr[i];
    }

    int i = 0;

    while (i < n - 1)
    {
        int j = 0;

        while (j < n - i - 1)
        {
            if (ascending[j] > ascending[j + 1])
            {
                int temp = ascending[j];
                ascending[j] = ascending[j + 1];
                ascending[j + 1] = temp;
            }

            j++;
        }

        i++;
    }

    i = 0;

    while (i < n - 1)
    {
        int j = 0;

        while (j < n - i - 1)
        {
            if (descending[j] < descending[j + 1])
            {
                int temp = descending[j];
                descending[j] = descending[j + 1];
                descending[j + 1] = temp;
            }

            j++;
        }

        i++;
    }

    printf("Ascending order:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", ascending[i]);

    printf("\n");

    printf("Descending order:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", descending[i]);

    printf("\n");

    return 0;
}
