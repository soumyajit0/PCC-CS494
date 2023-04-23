#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

float fractionalKnapsack(float weight[], float value[], float capacity, int n)
{
    int i;
    float knapsack_Weight = 0, knapsack_Value = 0;
    float quantity[n], value_weight[n];
    bool item[n];
    for (i = 0; i < n; i++)
    {
        quantity[i] = 0;
        value_weight[i] = value[i] / weight[i];
        item[i] = false;
    }
    while (true)
    {
        float max = INT_MIN;
        int index = -1;
        for (i = 0; i < n; i++)
        {
            if (value_weight[i] > max && item[i] == false)
            {
                index = i;
                max = value_weight[i];
            }
        }
        item[index] = true;
        if ((weight[index] + knapsack_Weight) <= capacity)
        {
            quantity[index] = weight[index];
            knapsack_Weight += weight[index];
            knapsack_Value += value[index];
        }
        else
        {
            knapsack_Value += (capacity - knapsack_Weight) / weight[index] * value[index];
            quantity[index] = (capacity - knapsack_Weight) / weight[index] * weight[index];
            knapsack_Weight += (capacity - knapsack_Weight) / weight[index];
            printf("\nThe Solution Vector is : \n< ");
            for (i = 0; i < n; i++)
            {
                printf("%0.2f ", quantity[i]);
            }
            printf(">\n");
            return knapsack_Value;
        }
    }
}

int main()
{
    int n, i;
    float capacity;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    float weight[n], value[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter the Weight of %d item : ", i + 1);
        scanf("%f", &weight[i]);
        printf("Enter the Value of %d item : ", i + 1);
        scanf("%f", &value[i]);
    }
    printf("Enter the Knapsack Capacity : ");
    scanf("%f", &capacity);
    printf("The Maxium Profit is : %0.2f\n", fractionalKnapsack(weight, value, capacity, n));
    return 0;
}