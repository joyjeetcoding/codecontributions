#include <stdio.h>

int bsearch(int arr[], int item, int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e-s)/2;

    while(s <= e)
    {
        if(arr[mid] == item)
            return mid;
        
        else if(arr[mid] < item)
            s = mid + 1;

        else
            e = mid - 1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int main()
{
    int arr[5];
    int n = 5, item;

    printf("Enter the elements(max. 5) in  ascending order: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the no. to be search: ");
    scanf("%d", &item);

    int bIndex;
    bIndex = bsearch(arr, item, n);

    if(bIndex == -1)
    {
        printf("Item not found");
    }
    else
    {
        printf("Item found at index %d and position %d", bIndex, bIndex+1);
    }

    return 0;
}