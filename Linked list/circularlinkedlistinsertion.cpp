#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int d)
    {
        this -> data = d;
        this -> next = NULL;
    }

    ~Node()
    {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insert(Node* &tail, int element, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        temp -> next = temp;
    }
    else
    {
        //non empty list
        //assuming that the element is presnt in the list

        Node* curr = tail;

        while(curr->data != element)
        {
            curr = curr -> next;
        }

        //element found and curr is reperenting the element node

        Node* temp2 = new Node(d);
        temp2 -> next = curr -> next;
        curr -> next = temp2;
    }
}

void print(Node* &tail)
{

    //The following part is not applicable to print the single node

    //Node* temp = tail;
    // while(tail->next != temp)
    // {
    //     cout << tail -> data << " ";
    //     tail = tail -> next;
    // }
    // cout << " ";

    Node* temp = tail;

    if(tail == NULL)
    {
        cout << "List is empty " <<endl;
    }

    do
    {
       cout << tail -> data << " ";
       tail = tail -> next; 
    } while (tail != temp);
    cout << endl;

    
}

int main()
{
    Node* tail = NULL;

    //inserting in the empty list
    insert(tail, 5, 3);
    print(tail);

    insert(tail, 3, 5);
    print(tail);

    insert(tail, 5, 7);
    print(tail);

    insert(tail, 7, 9);
    print(tail);

    insert(tail, 5, 6);
    print(tail);

    insert(tail, 9, 10);
    print(tail);

    insert(tail, 3, 4);
    print(tail);

    return 0;
}