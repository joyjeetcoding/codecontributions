#include<iostream>
using namespace std;

int main()
{
    int i = 2;
    int *p = &i;
    
    cout << "Address of i using pointer " << p <<endl;
    cout << "Address of i using address of operator " << &i <<endl;

    cout << "value of i " << i <<endl;
    cout << "Address of i using pointer " << *p <<endl;

    int n = 8;

    int *point = &n;
    cout << "Address is "<<point <<endl;
    cout << "Value is "<<*point << endl;


    int *ptr = 0;
    ptr = &n;

    cout << "Address is "<<ptr<<endl;
    cout << "Value is "<<*ptr <<endl;

    return 0;
}