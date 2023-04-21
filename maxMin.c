#include <stdio.h>

int max(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int a = max(arr, start, mid);
    int b = max(arr, mid + 1, end);
    if (a > b)
        return a;
    else
        return b;
}

int min(int arr[], int start, int end)
{
    if (start == end)
        return arr[start];
    int mid = (start + end) / 2;
    int a = min(arr, start, mid);
    int b = min(arr, mid + 1, end);
    if (a < b)
        return a;
    else
        return b;
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