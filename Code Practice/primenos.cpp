#include <iostream>
using namespace std;

int main()
{
    int lb, ub, count = 0, counttwodigit = 0, chk = 0;

    cout << "Enter the lower bound: ";
    cin >> lb;

    cout << "Enter the upper bound: ";
    cin >> ub;

    for(int i = lb; i <= ub; i++)
    {
        for(int j = 2; j < i; j++)
        {
            if(i % j == 0)
            {
                chk++;
                break;
            }
        }

        if(chk == 0 && i != 1)
        {
            cout << i << " ";
            if(i >= 10)
            {
                counttwodigit++;
            }
            count++;
        }
        chk = 0;
    }

    cout << endl;
    cout << "Total no. of prime nos.: " << count << endl;
    cout << "Two digit prime nos.: " << counttwodigit;

    return 0;
}