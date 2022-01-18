#include <string.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generateMatrix(int n, int *returnSize, int **returnColumnSizes)
{
    *returnSize = n;
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
    {
        (*returnColumnSizes)[i] = n;
    }

    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n);
        memset(matrix[i], NULL, sizeof(int) * n);
    }

    int num = 1;
    for (int i1 = n - 1, i2 = 0; i1 >= 1; i1--, i2++)
    {
        //从左上到右上
        for (int j = i2; j < i1; j++)
        {
            matrix[i2][j] = num++;
        }

        //从右上到右下
        for (int j = i2; j < i1; j++)
        {
            matrix[j][i1] = num++;
        }

        //从右下到左下
        for (int j = i1; j > i2; j--)
        {
            matrix[i1][j] = num++;
        }

        //从左下到左上
        for (int j = i1; j > i2; j--)
        {
            matrix[j][i2] = num++;
        }
    }

    if (n % 2)
    {
        matrix[n / 2][n / 2] = n * n;
    }

    return matrix;
}