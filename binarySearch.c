#include <stdio.h>

int binarySearch(int arr[], int start, int end, int key)
{
    if (end < start)
        return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, start, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, end, key);
}

int main()
{
    int key, n, i;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d", &key);
    int in = binarySearch(arr, 0, n - 1, key);
    if (in == -1)
        printf("Element not found\n");
    else
        printf("Element is found at : %d Index position\n", in);
    return 0;
}