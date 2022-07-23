#include<iostream>
using namespace std;

int main()
{
    
    // int arr[4] = {11, 21, 31, 41};
    // int* ptr = &arr[1];
    // arr++;
    // cout << *ptr << endl;
    

    char ch = "abcd";
    char* ptr = &ch;
    ch++;
    cout << *ptr <<endl;
    return 0;
}