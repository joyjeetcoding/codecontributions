#include <iostream>
using namespace std;

void update(int **p2)
{
    // p2 = p2+1;
    // No change on output

    // *p2 = *p2+1
    //change in output in the address of ptr

    // **p2 = **p2+1;
    //change in the output in the value of c

    
}

int main()
{
    int c = 6;
    // int *p = &c;
    int *ptr = &c;
    int **ptr2 = &ptr;

    // cout << p << endl;
    // cout << *p << endl;

   /* cout << *ptr << endl;
    cout << **ptr2 << endl;

    cout << "-----------------" << endl;
    cout << ptr << endl;
    cout << ptr2 << endl;
    cout << *ptr2 << endl;
    cout << "-----------------" << endl;
    cout << &c << endl;
    cout << ptr << endl;
    cout << *ptr2 <<endl;

    cout << "-----------------"<<endl;
    cout << ptr2 <<endl;
    cout << &ptr << endl;
    */

    cout << "Before " << c <<endl;
    cout << "Before " << ptr <<endl;
    cout << "Before " << ptr2 <<endl;
    update(ptr2);
    cout << "After " << c <<endl;
    cout << "After " << ptr <<endl;
    cout << "After " << ptr2 <<endl;

    return 0;
}