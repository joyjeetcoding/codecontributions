#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    // constructor
    Node(int data)
    {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertathead(Node* &head, int d)
{
    //create new node
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertattail(Node* &tail, int d)
{
    //create new node
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertatmiddle(Node* &head, Node* &tail, int position, int d)
{
    if(position == 1)
    {
        insertathead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while(cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }

    //inserting at last pos
    if(temp -> next == NULL)
    {
        insertattail(tail, d);
        return;
    }

    //creating a node for d
    Node* nodetoinsert = new Node(d);

    nodetoinsert -> next = temp -> next;

    temp -> next = nodetoinsert;
}

void print(Node* &head)
{
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
    Node* node1 = new Node(10);
    // cout << node1 -> data << endl;
    // cout << node1 -> next << endl;


    //head pointed to node1
    Node* head = node1;
    Node* tail = node1;

    print(head);

    insertattail(tail, 12);

    print(head);

    insertathead(head, 15);

    print(head);

    insertatmiddle(head, tail, 3, 22);
    print(head);

    cout << "Head " << head -> data << endl;
    cout << "Tail " << tail -> data << endl;

    return 0;
}