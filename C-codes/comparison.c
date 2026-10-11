#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

void bubble_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

void count_sort(int arr[], int n)
{
    int minimum = arr[0];
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minimum)
            minimum = arr[i];

        if (arr[i] > maximum)
            maximum = arr[i];
    }

    int range = maximum - minimum + 1;
    int *count = calloc(range, sizeof(int));

    for (int i = 0; i < n; i++)
        count[arr[i] - minimum]++;

    int index = 0;

    for (int i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            arr[index++] = i + minimum;
            count[i]--;
        }
    }

    free(count);
}

void counting_sort_radix(int arr[], int n, int position)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / position) % 10;
        count[digit]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / position) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(int arr[], int n)
{
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }

    int position = 1;

    while (maximum / position > 0)
    {
        counting_sort_radix(arr, n, position);
        position *= 10;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int position = partition(arr, low, high);

        quick_sort(arr, low, position - 1);
        quick_sort(arr, position + 1, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1];
    int right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = low;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

double measure(void (*sort_function)(int[], int), int arr[], int n)
{
    clock_t start = clock();

    sort_function(arr, n);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measure_quick(int arr[], int n)
{
    clock_t start = clock();

    quick_sort(arr, 0, n - 1);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

double measure_merge(int arr[], int n)
{
    clock_t start = clock();

    merge_sort(arr, 0, n - 1);

    clock_t end = clock();

    return (double)(end - start) / CLOCKS_PER_SEC;
}

int main()
{
    int sizes[] = {1000, 2000, 5000};

    srand(time(NULL));

    printf("SORTING ALGORITHM COMPARISON\n\n");

    printf("Size\tSelection\tBubble\t\tInsertion\tCount\t\tRadix\t\tHeap\t\tQuick\t\tMerge\n");

    for (int s = 0; s < 3; s++)
    {
        int n = sizes[s];

        int *original = malloc(n * sizeof(int));

        int *arr1 = malloc(n * sizeof(int));
        int *arr2 = malloc(n * sizeof(int));
        int *arr3 = malloc(n * sizeof(int));
        int *arr4 = malloc(n * sizeof(int));
        int *arr5 = malloc(n * sizeof(int));
        int *arr6 = malloc(n * sizeof(int));
        int *arr7 = malloc(n * sizeof(int));
        int *arr8 = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++)
            original[i] = rand() % 10001;

        for (int i = 0; i < n; i++)
        {
            arr1[i] = original[i];
            arr2[i] = original[i];
            arr3[i] = original[i];
            arr4[i] = original[i];
            arr5[i] = original[i];
            arr6[i] = original[i];
            arr7[i] = original[i];
            arr8[i] = original[i];
        }

        double selection_time = measure(selection_sort, arr1, n);
        double bubble_time = measure(bubble_sort, arr2, n);
        double insertion_time = measure(insertion_sort, arr3, n);
        double count_time = measure(count_sort, arr4, n);
        double radix_time = measure(radix_sort, arr5, n);
        double heap_time = measure(heap_sort, arr6, n);

        double quick_time = measure_quick(arr7, n);
        double merge_time = measure_merge(arr8, n);

        printf("%d\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\t%.6f\n",
               n,
               selection_time,
               bubble_time,
               insertion_time,
               count_time,
               radix_time,
               heap_time,
               quick_time,
               merge_time);

        free(original);
        free(arr1);
        free(arr2);
        free(arr3);
        free(arr4);
        free(arr5);
        free(arr6);
        free(arr7);
        free(arr8);
    }

    return 0;
}
