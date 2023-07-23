#include<iostream>
#include<vector>
using namespace std;

void printf(int ind, vector<int>& ds, int arr[], int n)
{
    if(ind >= n)
    {
        for(auto it: ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }

    ds.push_back(arr[ind]);
    printf(ind+1, ds, arr, n);
    ds.pop_back();

    printf(ind+1, ds, arr, n);
}

int main()
{
    int arr[3] = {1, 2, 2};
    vector<int> ds;
    printf(0, ds, arr, 3);

    return 0;
}