#include <stdio.h>

int main()
{
    int rows, columns;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int matrix1[rows][columns];
    int matrix2[rows][columns];
    int addition[rows][columns];
    int transpose1[columns][rows];

    printf("Enter elements of first matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element: ");
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Enter element: ");
            scanf("%d", &matrix2[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            addition[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    printf("Matrix addition:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            printf("%d ", addition[i][j]);

        printf("\n");
    }

    for (int j = 0; j < columns; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            transpose1[j][i] = matrix1[i][j];
        }
    }

    printf("Transpose of first matrix:\n");

    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
            printf("%d ", transpose1[i][j]);

        printf("\n");
    }

    return 0;
}
