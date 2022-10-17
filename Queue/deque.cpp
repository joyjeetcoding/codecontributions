#include<iostream>
using namespace std;

int main()
{
    int ch;

    do
    {
        cout << "1. Push_front()" << endl;
        cout << "2. Pop_front()" << endl;
        cout << "3. Push_rear()" << endl;
        cout << "4. Pop_rear()" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        
        case 4:
        break;

        case 5:
        break;
        
        default: cout << "Wrong Choice" << endl;
        break;
        }

    } while (ch != 5);
    return 0;
}