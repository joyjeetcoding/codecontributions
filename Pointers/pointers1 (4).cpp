#include <iostream>
using namespace std;

int main()
{
    // int arr[4] = {88,4,5,10};

    // cout << arr << endl;
    // cout << &arr[0] << endl;
    // cout << *arr <<endl;
    // cout << *arr + 1 <<endl;
    // cout << *(arr+1) <<endl;

    int arr[10];
    // ERROR
    // arr = arr + 1;
    // cout << arr;
    
    int *ptr = &arr[0];
    cout << ptr << endl;

    ptr = ptr+2;
    cout << ptr <<endl;

    return 0;
}