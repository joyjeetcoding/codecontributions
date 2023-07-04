#include<iostream>
#include<vector>
using namespace std;

int subsum(int ind, int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        if(s == sum)
            return 1;
        else
            return 0;
    }

    s += arr[ind];

    int left = subsum(ind+1, s, sum, arr, n);

    s -= arr[ind];

    int right = subsum(ind+1, s, sum, arr, n);
    
    return left + right;
}

int main()
{
    int arr[3] = {1, 2, 1};
    int s = 0;
    int sum = 2;

    cout << subsum(0, s, sum, arr, 3);


    return 0;
}