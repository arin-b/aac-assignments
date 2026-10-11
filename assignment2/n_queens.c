#include <stdio.h>
#include <stdlib.h>

int board[20], n, count = 0;

int isSafe(int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void solve(int row) {
    if (row == n) {
        printf("\nSolution %d:\n", ++count);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                printf("%c ", board[i] == j ? 'Q' : '.');
            printf("\n");
        }
        return;
    }

    // Try placing a queen in each column
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row] = col;
            solve(row + 1);
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Enter a value between 1 and 20.\n");
        return 1;
    }

    solve(0);

    if (count == 0)
        printf("No solution exists.\n");
    else
        printf("\nTotal solutions: %d\n", count);

    return 0;
}
