#include<iostream>
using namespace std;

void print(int i, int n)
{
    if(i < 1)
        return;
    print(i-1, n);
    cout << i << " ";
}

int main()
{
    int n;
    cout << " Enter the no. of times: " << endl;
    cin >> n;

    print(n, n);
    return 0;
}