#include <stdio.h>
#include <limits.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int arraySize)
{
    int i;
    for (i = arraySize / 2; i >= 1; i--)
    {
        int child1 = i * 2;
        int child2 = i * 2;
        if (arraySize & 1 == 1)
        {
            child2++;
        }
        else
        {
            child2--;
        }
        if (array[child1] < array[child2])
        {
            if (array[child1] < array[i])
            {
                swap(&array[i], &array[child1]);
            }
        }
        else
        {
            if (array[child2] < array[i])
            {
                swap(&array[i], &array[child2]);
            }
        }
    }
}

void heapSort(int array[], int arraySize)
{
    heapify(array, arraySize);
    while (array[1] != INT_MAX)
    {
        printf("%d ", array[1]);
        array[1] = INT_MAX;
        heapify(array, arraySize);
    }
    printf("\n");
}

int main()
{
    int arraySize, i;
    printf("Enter size of the array : ");
    scanf("%d", &arraySize);
    int array[arraySize + 1];
    array[0] = INT_MAX;
    printf("Enter the elements of the array : \n");
    for (i = 1; i <= arraySize; i++)
        scanf("%d", &array[i]);
    printf("The sorted array is : \n");
    heapSort(array, arraySize);
    return 0;
}