#include <stdio.h>

#define INF 99999

int main() {
    int n, graph[20][20], dist[20], visited[20] = {0}, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < n; count++) {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] > 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Shortest distances from vertex %d:\n", source);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d -> %d : INF\n", source, i);
        else
            printf("%d -> %d : %d\n", source, i, dist[i]);
    }

    return 0;
}
