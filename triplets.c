#include <stdio.h>
void findTriplet(int arr[], int n)
{
    int i, j, k;
    int x = -1, y = -1, z = -1, value, max = -9999999;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (i != j && j != k && i != k)
                {
                    printf("(%d,%d,%d)\n", arr[i], arr[j], arr[k]);
                    value = (arr[i] - arr[j]) * arr[k];
                    if (value > max)
                    {
                        x = i, y = j, z = k;
                        max = value;
                    }
                }
            }
        }
    }
    printf("Maximum Tuple: (%d,%d,%d) \t Max Value = %d\n", arr[x], arr[y], arr[z], max);
}
int main()
{
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    findTriplet(arr, n);
    return 0;
}
