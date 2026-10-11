#include <stdio.h>

int binary_search_iterative(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int binary_search_recursive(int arr[], int low, int high, int key)
{
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;

    if (arr[mid] < key)
        return binary_search_recursive(arr, mid + 1, high, key);

    return binary_search_recursive(arr, low, mid - 1, key);
}

int main()
{
    int n, key;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in ascending order:\n");

    for (int i = 0; i < n; i++)
    {
        printf("Enter element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int result1 = binary_search_iterative(arr, n, key);
    int result2 = binary_search_recursive(arr, 0, n - 1, key);

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
