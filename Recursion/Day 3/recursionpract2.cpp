#include<iostream>
using namespace std;
int cnt = 1;

void print(int cnt, int n)
{
    if(cnt == n+1)
        return;
    
    cout << cnt << endl;
    cnt++;
    print(cnt, n);
}

int main()
{
    int n;
    cout << "Enter the no. of times: " << endl;
    cin >> n;

    print(cnt, n);
    return 0;
}