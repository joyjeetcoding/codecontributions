#include<iostream>
using namespace std;

void print(int arr[], int s, int e)
{
    for(int i = s; i <= e; i++)
        cout << arr[i] <<" ";
    cout << endl;
}

bool bsearch(int arr[], int s, int e, int k)
{
    print(arr,s,e);

    //base case
    if(s > e)
        return false;

    int mid = s + (e-s)/2;
    cout << "Value of mid is " << arr[mid] << endl;

    if(arr[mid] == k)
        return true;



    //right part
    if(arr[mid] < k)
        return bsearch(arr, mid+1, e, k);
    //left part
    else
        return bsearch(arr, s, mid-1,k);

}

int main()
{
    int arr[6] = {2,4,5,8,10,14};
    int size = 6;

    int key = 14;

    cout << "Present or not " << bsearch(arr,0,5,key) << endl;

    return 0;
}