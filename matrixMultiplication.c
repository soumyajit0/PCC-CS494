#include <stdio.h>
#include <limits.h>

int n;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    return b;
}

int MCM(int arr[], int i, int j, int dp[n + 1][n + 1])
{
    if (i >= j - 1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int k;
    int res = INT_MAX;
    for (k = i + 1; k < j; k++)
    {
        res = min(res, MCM(arr, i, k, dp) + MCM(arr, k, j, dp) + arr[i] * arr[k] * arr[j]);
    }
    dp[i][j] = res;
    return res;
}

int main()
{
    int i, j;
    printf("Enter the no. of Matrices : ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter the Dimensions of the Matrices : ");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (n <= 1)
    {
        printf("The Minimum No. of Operations : 0\n");
        return 0;
    }
    else if (n == 2)
    {
        printf("The Minimum No. of Operations : %d\n", arr[0] * arr[1] * arr[2]);
        return 0;
    }
    int dp[n + 1][n + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            dp[i][j] = -1;
        }
    }
    printf("The Minimum No. of Operations : %d\n", MCM(arr, 0, n, dp));
    return 0;
}