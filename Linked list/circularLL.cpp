#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;


Node* circularLL()
{
    int n;
    // Node* temp = head;

    cout << "Enter the no. of nodes: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        Node* temp = new Node();

        cout << "Enter data: ";
        cin >> temp->data;

        if(head == NULL)
        {
            cout << "hii";
            head = temp;
            tail = temp;
            temp -> next = head;
        }

        else
        {
            tail -> next = temp;
            tail = temp;
            tail -> next = head;
        }

    }

    return head;
}

void display(Node* head)
{
    Node* temp = head;
    do
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    } while (temp != head);
    
    cout << endl;
}

int main()
{
    int ch;

    Node* node1 = new Node();
    Node* head = node1;

    do
    {
        cout << "1. Create a Circular Linked List" << endl;
        cout << "2. Delete a node at the beginning" << endl;
        cout << "3. Delete a node at the end" << endl;
        cout << "4. Delete a node of a given index" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1: head = circularLL();
        display(head);
            break;
        
        default:
            break;
        }
    } while (ch!=5);
    
    
    return 0;
}