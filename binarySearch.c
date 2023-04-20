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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n;
    printf("Enter the element to be searched : ");
    scanf("%d", &n);
    int in = binarySearch(arr, 0, sizeof(arr) / 4 - 1, n);
    if (in == -1)
        printf("Element not found\n");
    else
        printf("Element is found at : %d index position\n", in);
    return 0;
}