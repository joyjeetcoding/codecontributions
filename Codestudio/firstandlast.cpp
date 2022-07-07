#include<iostream>
using namespace std;

int firstocc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }
    return ans;

}

int lastocc(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int ans = -1;
    int mid = s + (e - s)/2;

    while(s <= e)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if(arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s)/2;
    }
    return ans;

}

int main()
{
    int arr[6] = {1,2,3,5,5,6};

    cout << "First occurrence of 5 is at index "<< firstocc(arr,6,5) << endl;
    cout << "Last occurrence of 5 is at index "<< lastocc(arr,6,5) << endl;


    return 0;
}