#include <stdio.h>

int main()
{
    int rows1, columns1, rows2, columns2;

    printf("Enter number of rows of first matrix: ");
    scanf("%d", &rows1);

    printf("Enter number of columns of first matrix: ");
    scanf("%d", &columns1);

    printf("Enter number of rows of second matrix: ");
    scanf("%d", &rows2);

    printf("Enter number of columns of second matrix: ");
    scanf("%d", &columns2);

    if (columns1 != rows2)
    {
        printf("Matrix multiplication is not possible.\n");
    }
    else
    {
        int matrix1[rows1][columns1];
        int matrix2[rows2][columns2];
        int result[rows1][columns2];

        printf("Enter elements of first matrix:\n");

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns1; j++)
            {
                printf("Enter element: ");
                scanf("%d", &matrix1[i][j]);
            }
        }

        printf("Enter elements of second matrix:\n");

        for (int i = 0; i < rows2; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                printf("Enter element: ");
                scanf("%d", &matrix2[i][j]);
            }
        }

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
            {
                result[i][j] = 0;

                for (int k = 0; k < columns1; k++)
                {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }

        printf("Matrix multiplication:\n");

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < columns2; j++)
                printf("%d ", result[i][j]);

            printf("\n");
        }
    }

    return 0;
}
