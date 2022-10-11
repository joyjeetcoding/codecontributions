#include<iostream>
using namespace std;

bool f(int i, string str, int n)
{
    if(i >= n/2)
        return true;

    if(str[i] != str[n - i - 1])
        return false;
    
    return f(i+1, str, n);
}

int main()
{
    string str = "madam";
    int n = str.size();
    cout << f(0, str, n);
    

    return 0;
}