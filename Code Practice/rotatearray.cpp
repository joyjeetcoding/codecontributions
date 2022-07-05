#include<iostream>
using namespace std;


void print(int ans[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] <<" ";
    }
    
}

int main()
{
    int n=0, k=0;
    int arr[n];

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[n];
    cin >> k;
    for(int i = 0; i < n; i++)
    {
        arr[(i+k) % n] = arr[i];
    }

    print(arr,5);

    return 0;
}