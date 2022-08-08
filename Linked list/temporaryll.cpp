#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

int main()
{
    int ch;
    cout << " Enter your choice " << endl;
    cout << " Create Linked List " << endl;
    cout << " Insertion at head " << endl;
    cout << " Insertion at tail " << endl;
    cout << " Insertion at any position " << endl;
    cin >> ch;
    switch(ch)
    {
        case 1: create();
        break;
        case 2: insertathead();
        break;
        case 3: insertatatil();
        break;
        case 4: insertatanyposition();
        break;
        case 0: 
        break;
        default: cout << " Wrong Choice" <<endl;
        break;
    }

    return 0;
}
