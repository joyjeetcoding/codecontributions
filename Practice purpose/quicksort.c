#include<stdio.h>

int partition(int* arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    int pivotIndex;

    for(int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot)
            count++;
    }

    pivotIndex = s + count;
    int temp = arr[s];
    arr[s] = arr[pivotIndex];
    arr[pivotIndex] = temp;

    int  i = s, j = e;

    while(i < pivotIndex && j > pivotIndex)
    {
        while(arr[i] < pivot)
            i++;

        while(arr[j] > pivot)
            j--;

        if(i < pivotIndex && j > pivotIndex)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    return pivotIndex;
}

void quicksort(int* arr, int s, int e)
{
    // base case
    if(s >= e)
        return;

    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{
    int n = 6;
    int arr[6] = {23, 11, 25, 6, 2, 8};

    quicksort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}