#include <stdio.h>

#define INF 99999

int main() {
    int n, graph[20][20], visited[20] = {0};
    int edges = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1;
    printf("Edges in Minimum Spanning Tree:\n");

    while (edges < n - 1) {
        int min = INF, u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] > 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);
        visited[v] = 1;
        minCost += min;
        edges++;
    }

    printf("Minimum cost = %d\n", minCost);
    return 0;
}
