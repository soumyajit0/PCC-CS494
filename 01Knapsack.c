#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int knapsack01(int n, int value[], int weight[], int capacity)
{
    int dp[n + 1][capacity + 1];
    int i, j;
    for (i = 0; i <= capacity; i++)
        dp[0][i] = 0;
    for (i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= capacity; j++)
        {
            if (weight[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max((value[i - 1] + dp[i - 1][j - weight[i - 1]]), dp[i - 1][j]);
        }
    }
    return dp[n][capacity];
}

int main()
{
    int n, i, capacity, profit = 0;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    int value[n], weight[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the Value of %d Item : ", i + 1);
        scanf("%d", &value[i]);
        printf("Enter the Weight of %d Item : ", i + 1);
        scanf("%d", &weight[i]);
    }
    printf("Enter the Knapsack Capacity : ");
    scanf("%d", &capacity);
    profit = knapsack01(n, value, weight, capacity);
    printf("Total Profit : %d\n", profit);
    return 0;
}