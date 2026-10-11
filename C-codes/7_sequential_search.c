#include <stdio.h>

int sequential_search_iterative(int arr[], int n, int key)
{
    int i = 0;

    while (i < n)
    {
        if (arr[i] == key)
            return i;

        i = i + 1;
    }

    return -1;
}

int sequential_search_recursive(int arr[], int n, int key, int i)
{
    if (i == n)
        return -1;

    if (arr[i] == key)
        return i;

    return sequential_search_recursive(arr, n, key, i + 1);
}

int main()
{
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result1 = sequential_search_iterative(arr, n, key);
    int result2 = sequential_search_recursive(arr, n, key, 0);

    if (result1 == -1)
        printf("Element not found using iterative search.\n");
    else
        printf("Element found at position %d using iterative search.\n",
               result1 + 1);

    if (result2 == -1)
        printf("Element not found using recursive search.\n");
    else
        printf("Element found at position %d using recursive search.\n",
               result2 + 1);

    return 0;
}
