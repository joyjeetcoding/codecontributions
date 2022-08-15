#include<iostream>
using namespace std;

int power(int n)
{
    //Base Case
    if(n == 0)
        return 1;
    
    //recursive relation
    int smallprob = power(n-1);
    int bigprob = 2 * smallprob;

    return bigprob;
}


int main()
{
    int n;
    cin >> n;

    int ans = power(n);

    cout << ans <<endl;


    return 0;
}