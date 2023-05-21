#include <stdio.h>
#include <limits.h>

void activitySelection(int A[], int s[], int f[], int job[], int n, int finish)
{
    int end = 0;
    int i;
    while (end < finish)
    {
        int mn = INT_MAX, index = -1;
        for (i = 0; i < n; i++)
        {
            if (f[i] < mn && job[i] == INT_MIN && end <= s[i])
            {
                mn = f[i];
                index = i;
            }
        }
        job[index] = A[index];
        end = mn;
    }
}

int main()
{
    int n, i, finish = INT_MIN;
    printf("Enter no. of Jobs : ");
    scanf("%d", &n);
    int A[n], s[n], f[n], job[n];
    printf("Enter the Job no.s : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Enter the Job Starting time : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }
    printf("Enter the Job Ending time : ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &f[i]);
        if (f[i] > finish)
            finish = f[i];
    }
    for (i = 0; i < n; i++)
    {
        job[i] = INT_MIN;
    }
    activitySelection(A, s, f, job, n, finish);
    printf("The compatible Jobs are : \n");
    for (i = 0; i < n; i++)
    {
        if (job[i] == INT_MIN)
            continue;
        printf("%d ", job[i]);
    }
    printf("\n");
    return 0;
}