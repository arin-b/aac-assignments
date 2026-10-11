#include <stdio.h>

int main() {
    int n;
    float capacity, profit = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[n], value[n], ratio[n], temp;

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%f %f", &weight[i], &value[i]);
        ratio[i] = value[i] / weight[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by value-to-weight ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
                temp = value[i]; value[i] = value[j]; value[j] = temp;
            }
        }
    }

    // Greedily select items
    for (int i = 0; i < n && capacity > 0; i++) {
        if (weight[i] <= capacity) {
            profit += value[i];
            capacity -= weight[i];
        } else {
            profit += ratio[i] * capacity;
            capacity = 0;
        }
    }

    printf("Maximum profit = %.2f\n", profit);
    return 0;
}
