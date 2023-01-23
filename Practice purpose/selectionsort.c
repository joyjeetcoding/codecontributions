#include<stdio.h>

int main()
{
    int arr[5];
    int n = 5;
    printf("Enter the nos. to be sorted using selection sort: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    //Selection Sort

    for(int i = 0; i < (n - 1); i++)       //loop for the rounds 
    {
        for(int j = i+1; j < (n-1); j++)    //loop for the nest elements
        {
            if(arr[i] > arr[j])             //check whether the element is bigger than the enxt element or not
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}