#include <stdio.h>

int main() {
    int n, adj[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = 0, count = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Enqueue vertices with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            queue[rear++] = i;
    }

    printf("Topological order: ");

    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[v][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n)
        printf("\nTopological sorting not possible (cycle detected).");

    return 0;
}
