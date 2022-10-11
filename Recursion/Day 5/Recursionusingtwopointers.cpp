#include<iostream>
using namespace std;

void reverseusingtwopointer(int arr[], int l, int r)
{
    if(l >= r)
        return;
    
    swap(arr[l], arr[r]);
    reverseusingtwopointer(arr, l+1, r-1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    reverseusingtwopointer(arr, 0, n-1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}