#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int jobSequencing(int jobs, int profit[], int deadline[], int slot[], int maxDeadline)
{
    int jobProfit = 0, i, count = 0;
    bool fixed[jobs];
    for (i = 0; i < jobs; i++)
    {
        fixed[i] = false;
    }
    while (count < maxDeadline)
    {
        int max = INT_MIN, index = -1, jobDeadline = -1;
        for (i = 0; i < jobs; i++)
        {
            if (profit[i] > max && fixed[i] == false)
            {
                max = profit[i];
                jobDeadline = deadline[i];
                index = i;
            }
        }
        fixed[index] = true;
        for (i = jobDeadline - 1; i >= 0; i--)
        {
            if (slot[i] == INT_MIN)
            {
                slot[i] = index + 1;
                jobProfit += profit[index];
                count++;
                break;
            }
        }
    }
    return jobProfit;
}

void printSlot(int slot[], int maxDeadline)
{
    printf("\n");
    int i;
    for (i = 0; i < maxDeadline; i++)
    {
        if (slot[i] == INT_MIN)
            continue;
        printf("Slot %d for Job %d\n", i + 1, slot[i]);
    }
}

int main()
{
    int jobs, i, maxDeadline = INT_MIN, jobProfit;
    printf("Enter the no. of Jobs : ");
    scanf("%d", &jobs);
    int profit[jobs], deadline[jobs];
    for (i = 0; i < jobs; i++)
    {
        printf("Enter the Profit from Job %d : ", i + 1);
        scanf("%d", &profit[i]);
        printf("Enter the Deadline from Job %d : ", i + 1);
        scanf("%d", &deadline[i]);
        if (maxDeadline <= deadline[i])
            maxDeadline = deadline[i];
    }
    int slot[maxDeadline];
    for (i = 0; i < maxDeadline; i++)
        slot[i] = INT_MIN;
    jobProfit = jobSequencing(jobs, profit, deadline, slot, maxDeadline);
    printSlot(slot, maxDeadline);
    printf("Total Profit : %d\n", jobProfit);
    return 0;
}