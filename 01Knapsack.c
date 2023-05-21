#include <stdio.h>
int n, cap;

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

int knapsack(int n, int cap, int wt[], int val[], int dp[n][cap])
{
    if (n == 0)
    {
        if (wt[0] <= cap)
            return val[0];
        return 0;
    }
    if (dp[n][cap] != -1)
        return dp[n][cap];
    int without = knapsack(n - 1, cap, wt, val, dp) + 0;
    int with = 0;
    if (wt[n] <= cap)
        with = knapsack(n - 1, cap - wt[n], wt, val, dp) + val[n];
    return dp[n][cap] = max(without, with);
}

int main()
{
    int i, j;
    printf("Enter no. of Items : ");
    scanf("%d", &n);
    int wt[n], val[n];
    printf("Enter the Weights and Values of the Items : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &wt[i], &val[i]);
    }
    printf("Enter the Knapsack Capacity : ");
    scanf("%d", &cap);
    int dp[n][cap + 1];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= cap; j++)
        {
            dp[i][j] = -1;
        }
    }
    printf("The Maximum Value is : %d\n", knapsack(n-1, cap, wt, val, dp));
    return 0;
}