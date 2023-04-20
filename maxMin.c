#include <stdio.h>

int max(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int p = max(arr, start, mid);
    int q = max(arr, mid + 1, end);
    if (p > q)
        return p;
    else
        return q;
}

int min(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int p = min(arr, start, mid);
    int q = min(arr, mid + 1, end);
    if (p < q)
        return p;
    else
        return q;
}

int main()
{
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int mx = max(arr, 0, n - 1);
    int mn = min(arr, 0, n - 1);
    printf("The maximum number is : %d\n", mx);
    printf("The minimum number is : %d\n", mn);
    return 0;
}