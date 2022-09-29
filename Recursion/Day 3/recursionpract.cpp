#include<iostream>
using namespace std;

// int cnt = 0;

// void func(char name[])
// {
//     if(cnt == 10)
//         return;
//     cout << name << endl;
//     cnt++;
//     func(name);
// }

// int main()
// {
//     char name[30] = "Joyjeet";

//     func(name);
//     return 0;
// }


//Another method

void print(int i, int n)
{
    if(i > n)
        return;
    
    cout << " Joyjeet " << endl;
    print(i + 1, n);
}

int main()
{

    int n;
    cout << " Enter the no. of times you want to print ? "<< endl;

    cin >> n;

    print(1, n);
    return 0;
}