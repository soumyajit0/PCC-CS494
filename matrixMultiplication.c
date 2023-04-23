#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int matrixMultiplication(int n, int array[])
{
    int dp[n][n];
    int i, j, k, gap;
    for (i = 0; i < n - 1; i++)
        dp[i][i + 1] = 0;
    for (gap = 2; gap < n; gap++)
    {
        for (i = 0; i + gap < n; i++)
        {
            j = i + gap;
            dp[i][j] = INT_MAX;
            for (k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + array[i] * array[j] * array[k]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n, i;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the Array : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &array[i]);
    printf("The Minimum No. of Multiplications needed : %d\n", matrixMultiplication(n, array));
    return 0;
}