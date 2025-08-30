#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

int sum (int *arr, int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

int avg (int *arr, int n)
{
    if (n == 0) return 0;
    int total = sum(arr, n);
    return total / n;
}

int min (int *arr, int n)
{
    int minVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < minVal)
        {
            minVal = arr[i];
        }
    }
    return minVal;
}

int max (int *arr, int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void SetOperationNumbers()
{
    int n;
    printf("Enter Numbers Of Items : ");
    scanf("%d",&n);
    if (n <= 0)
    {
        printf("Invalid Number ... Exiting\n");
        return;
    }
    int *numbers = (int*) malloc (n * sizeof(int));
    if (numbers == NULL)
    {
        printf("Dynamic Allocation Failed");
        return;
    }
    printf("Enter %d Integers : \n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
    printf("===================\n");
    printf("Sum : %d\n", sum(numbers, n));
    printf("Avg : %d\n", avg(numbers, n));
    printf("Min : %d\n", min(numbers, n));
    printf("Max : %d\n", max(numbers, n));
    printf("===================\n");
    free(numbers);
}

