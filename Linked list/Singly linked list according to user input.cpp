#include <iostream>
#include<process.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node* create()
{
    Node* head = new Node();
    Node* temp = head;

    int n;
    cout << "Enter the no. of nodes: " <<endl;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter the data " <<endl;
        cin >> temp -> data;

        if(i == n)
        {
            temp -> next = NULL;
        }

        else
        {
            temp -> next = new Node();
        }
        temp = temp -> next;
    }
    return head;
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << endl;
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertathead(Node* &head)
{
    Node* temp = new Node();
    cout << "Enter the value "<< endl;
    cin >> temp -> data;
    temp -> next = head;
    head = temp;
}

void insertattail(Node* head)
{
    Node* newnode = new Node();
    cout << "Enter the value: " << endl;
    cin >> newnode -> data;
    

    if(head == NULL)
        head = newnode;
    else
    {
        Node* temp = head;
        while(temp -> next != NULL)
        {
            temp = temp -> next;
        }
    temp -> next = newnode;
    }
    
}

void insertatanyposition(Node* &head)
{
    Node* newnode = new Node();
    Node* temp = head;

    int val;
    cout << "Enter the value of the node after which new node will be entered: " <<endl;
    cin >> val;

    cout << "Enter the value of the node: " << endl;
    cin >> newnode -> data;
    while(temp -> data != val)
    {
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

int main()
{
    Node* node1 = new Node();
    Node* head = node1;
    
    int ch;

    do
    {
        cout << " 1. Create Linked List " << endl;
        cout << " 2. Insertion at head " << endl;
        cout << " 3. Insertion at tail " << endl;
        cout << " 4. Insertion at any position " << endl;
        cout << " 5. Exit " << endl;
        cout << " Enter your choice " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            head = create();
            print(head);
            break;
        case 2:
            insertathead(head);
            print(head);
            break;
        case 3:
            insertattail(head);
            print(head);
            break;
        case 4:
            insertatanyposition(head);
            print(head);
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << " Wrong Choice" << endl;
            break;
        }
    } while (ch != 5);

    return 0;
}
