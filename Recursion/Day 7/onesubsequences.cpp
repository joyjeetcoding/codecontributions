#include<iostream>
#include<vector>
using namespace std;

bool subsum(int ind, vector<int> &ds, int s, int sum, int arr[], int n)
{
    if(ind == n)
    {
        if(s == sum)
        {
            for(auto it: ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        
        else
            return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if(subsum(ind+1, ds, s, sum, arr, n) == true)
        return true;

    s -= arr[ind];
    ds.pop_back();

    if(subsum(ind+1, ds, s, sum, arr, n) == true)
        return true;
    
    return false;
}

int main()
{
    int arr[3] = {1, 2, 1};
    vector<int> ds;
    int s = 0;
    int sum = 2;

    subsum(0, ds, s, sum, arr, 3);


    return 0;
}