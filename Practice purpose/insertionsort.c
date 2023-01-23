#include<stdio.h>

int main()
{
    int arr[5];
    int n = 5;
    printf("Enter the elements to be sorted using insertion sort: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

// insertion sort
    for(int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for(; j >= 0; j--)
        {
            if(arr[j] > temp)
            {
                arr[j+1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j+1] = temp;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}