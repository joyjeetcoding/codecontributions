#include<iostream>
using namespace std;

void sumfunction(int i, int sum)
{
    if(i < 1)
    {
        cout << "The sum is " << sum;
        return;
    }

    sumfunction(i-1, sum + i);

}

int main()
{
    int n;

    cout << "Enter the no.: " << endl;
    cin >> n;

    sumfunction(n, 0);
    return 0;
}