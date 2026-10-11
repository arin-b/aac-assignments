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

    int minimum = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minimum)
            minimum = arr[i];

        if (arr[i] > maximum)
            maximum = arr[i];
    }

    int range_size = maximum - minimum + 1;
    int count[range_size];

    for (int i = 0; i < range_size; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i] - minimum]++;

    int ascending[n];
    int descending[n];

    int index = 0;

    for (int i = 0; i < range_size; i++)
    {
        int j = 0;

        while (j < count[i])
        {
            ascending[index] = i + minimum;
            index++;
            j++;
        }
    }

    index = 0;

    for (int i = range_size - 1; i >= 0; i--)
    {
        int j = 0;

        while (j < count[i])
        {
            descending[index] = i + minimum;
            index++;
            j++;
        }
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
