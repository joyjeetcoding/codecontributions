#include<stdio.h>

void merge(int* arr, int s, int e)
{
    int mid = s + (e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int first[len1];
    int second[len2];

// Copy the values
    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i = 0; i < len1; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // Merge the 2 sorted arrays
    
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2)
    {
        if(first[index1] <= second[index2])
        {
            arr[mainArrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void mergesort(int* arr, int s, int e)
{

    // base case
    if(s >= e)
        return;
    
    int mid = s + (e - s)/2;

    // left part
    mergesort(arr, s, mid);

    // right part
    mergesort(arr, mid + 1, e);

    // Merge the arrays
    merge(arr, s, e);
    

}


int main()
{
    int n = 6;
    int arr[6] = {23, 11, 25, 6, 2, 8};

    mergesort(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}