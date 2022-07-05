#include<iostream>
using namespace std;

void sortArray(int arr[],int n)
{
    int left = 0, right = n - 1;
    while(left < right)
    {
        while(arr[left] == 1 && left < right)
        {
            left++;
        }

        while(arr[right] == 1 && left < right)
        {
            right--;
        }

        if(left < right && arr[left] == 0 && arr[right] == 1)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

void printArray(int arr[],int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
}

int main()
{
    int arr[8] = {1,1,0,0,0,0,1,0};

    sortArray(arr,8);
    printArray(arr,8);


    return 0;
}