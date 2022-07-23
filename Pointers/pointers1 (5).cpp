#include<iostream>
using namespace std;

int main()
{
    char ch[6] = "abcde";
    int arr[5] = {1, 2, 3, 4, 5};

    cout << ch << endl;
    cout << arr << endl;

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;
    return 0;
}