#include<iostream>
#include<vector>

using namespace std;

void movezero(int arr[], int n)
{
    int i = 0;

    for(int j = 0; j < 5; j++)
    {
        if(arr[j] != 0)
        {
            swap(arr[j],arr[i]);
            i++;
        }

    }
}

void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] <<" ";
    }
    
}

int main()
{
    int arr[5] = {1,0,5,6,0};
    
    movezero(arr,5);

    print(arr,5);


    return 0;
}