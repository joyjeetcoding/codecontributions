#include<iostream>
using namespace std;

int main()
{
    int num = 5;
    int *p = &num;

    // * is a dereference operator
    cout << "Value after using pointer *p "<< *p <<endl;
    cout << "Address of num using p "<< p <<endl;

    cout << "Size of num "<< sizeof(num) <<endl;
    cout << "Size of pointer "<<sizeof(*p)<<endl;

    //address of operator = &

    cout << "Address of num using &num (address of operator) "<< &num << endl;
    cout <<"Value after using num "<< num << endl;

    double n = 87.3;
    double *ptr = &n;

    cout << "Address of double value "<<ptr<<endl;
    cout << "Value after using pointer "<<*ptr<<endl;

    cout << "Size of double "<< sizeof(double) <<endl;
    cout << "Size of pointer "<<sizeof(ptr)<<endl;

    char ch = 'a';
    char *cha = &ch;
    cout << "Size of char "<< sizeof(char) <<endl;
    cout << "Size of pointer "<<sizeof(cha)<<endl;

    return 0;
}