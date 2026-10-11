#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int n, capacity, weight[20], value[20], dp[21][1001] = {0};

    printf("Enter number of items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &weight[i], &value[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Dynamic Programming
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weight[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w],
                               value[i - 1] + dp[i - 1][w - weight[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}
