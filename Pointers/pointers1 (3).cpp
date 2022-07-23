#include <iostream>
using namespace std;

int main()
{
    // int n = 9;
    // int *p = &n;
    // cout << "Before n value is " << n << endl;

    // // (*p)++;
    // cout << "After using *p++, n value we get " << n << endl;

    // int *q = p;

    // cout << "Value of pointer p " << *p << endl;
    // cout << "Value after copying from p to pointer q " << *q << endl;

    // cout << "address of pointer p " << p << endl;
    // cout << "address after copying from p to pointer q " << q << endl;

    // int i = 5;
    // int *ptr = &i;

    // (*ptr)++;

    // cout << *ptr << endl;
    // cout << ptr << endl;

    // ptr++;

    // cout << ptr;

    int a = 100, b = 200;
    int *p = &a, *q = &b;
    p = q;

    cout << *p;

    return 0;
}