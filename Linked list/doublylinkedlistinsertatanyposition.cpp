#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    
    ~Node()
    {
        int val = this -> data;
        if(next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

void insertathead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertatanyposition(Node* &head, Node* &tail, int position, int d)
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

    if(temp -> next == NULL)
    {
        insertattail(tail,d);
        return;
    }

    Node* Nodetoinsert = new Node(d);
    Nodetoinsert -> next = temp -> next;
    temp -> next -> prev = Nodetoinsert;
    temp -> next = Nodetoinsert;
    Nodetoinsert -> prev = temp;


}

void deletion(int position, Node* &head)
{
    if(position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;

        delete temp;

    }
    else
    {
        //last node and middle node deletion
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr= curr ->next;
            cnt++;
        }
        
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);
    // cout << endl;
    cout << getLength(head) << endl;

    insertathead(head, 24);
    print(head);

    insertattail(tail, 50);
    print(head);

    insertatanyposition(head, tail, 2, 45);
    print(head);

    deletion(3, head);
    print(head);
    cout << "Head = " << head -> data << endl;
    cout << "Tail = " << tail -> data << endl;
    
    deletion(1, head);
    print(head);
    cout << "Head = " << head -> data << endl;
    cout << "Tail = " << tail -> data << endl;

    return 0;
}