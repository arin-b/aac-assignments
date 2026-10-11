#include <stdio.h>
#include <stdlib.h>

int **create(int n) {
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = calloc(n, sizeof(int));
    return a;
}

void freeMatrix(int **a, int n) {
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}

void add(int **A, int **B, int **C, int n, int sign) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + sign * B[i][j];
}

void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int **a[4], **b[4], **p[7];

    for (int x = 0; x < 4; x++) {
        a[x] = create(k);
        b[x] = create(k);
    }
    for (int x = 0; x < 7; x++)
        p[x] = create(k);

    int **t1 = create(k), **t2 = create(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            a[0][i][j] = A[i][j];
            a[1][i][j] = A[i][j+k];
            a[2][i][j] = A[i+k][j];
            a[3][i][j] = A[i+k][j+k];

            b[0][i][j] = B[i][j];
            b[1][i][j] = B[i][j+k];
            b[2][i][j] = B[i+k][j];
            b[3][i][j] = B[i+k][j+k];
        }

    add(a[0], a[3], t1, k, 1);
    add(b[0], b[3], t2, k, 1);
    strassen(t1, t2, p[0], k);

    add(a[2], a[3], t1, k, 1);
    strassen(t1, b[0], p[1], k);

    add(b[1], b[3], t2, k, -1);
    strassen(a[0], t2, p[2], k);

    add(b[2], b[0], t2, k, -1);
    strassen(a[3], t2, p[3], k);

    add(a[0], a[1], t1, k, 1);
    strassen(t1, b[3], p[4], k);

    add(a[2], a[0], t1, k, -1);
    add(b[0], b[1], t2, k, 1);
    strassen(t1, t2, p[5], k);

    add(a[1], a[3], t1, k, -1);
    add(b[2], b[3], t2, k, 1);
    strassen(t1, t2, p[6], k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j] = p[0][i][j] + p[3][i][j] - p[4][i][j] + p[6][i][j];
            C[i][j+k] = p[2][i][j] + p[4][i][j];
            C[i+k][j] = p[1][i][j] + p[3][i][j];
            C[i+k][j+k] = p[0][i][j] - p[1][i][j] + p[2][i][j] + p[5][i][j];
        }

    for (int x = 0; x < 4; x++) {
        freeMatrix(a[x], k);
        freeMatrix(b[x], k);
    }
    for (int x = 0; x < 7; x++)
        freeMatrix(p[x], k);

    freeMatrix(t1, k);
    freeMatrix(t2, k);
}

int main() {
    int n, size = 1;

    printf("Enter matrix order: ");
    scanf("%d", &n);

    if (n <= 0) return 1;

    while (size < n)
        size *= 2;

    int **A = create(size);
    int **B = create(size);
    int **C = create(size);

    printf("Enter first matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter second matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, size);

    printf("Resultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    freeMatrix(A, size);
    freeMatrix(B, size);
    freeMatrix(C, size);

    return 0;
}
