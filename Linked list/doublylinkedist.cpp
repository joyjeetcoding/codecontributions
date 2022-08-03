#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d)
    {
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << endl;
        temp = temp -> next;
    }
}

int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;

    while(temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;

    print(head);
    cout << getLength(head) << endl;

    return 0;
}