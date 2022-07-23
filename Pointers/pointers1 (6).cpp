#include<iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}

void update(int *p)
{

    // p = p + 1;
    // cout << "In the update function " << p <<endl;

    *p = *p + 1;
}

int getsum(int arr[], int n)
{
    cout << endl << "Size "<< sizeof(arr) << endl;


    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
   /* int value = 5;
    int *p = &value;

    print(p);

    
    

    cout << "Before:  "<< *p << endl;
    update(p);
    cout << "After in the main ():  "<< *p << endl;
    */

    int arr[6] = {1, 2, 3, 4, 5,6};

    cout << "Sum is " << getsum(arr+3, 3) << endl;

    return 0;
}