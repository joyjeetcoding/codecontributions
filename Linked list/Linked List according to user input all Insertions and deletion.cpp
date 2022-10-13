#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    ~Node()
    {
        int value = this -> data;

        if(this -> next != NULL)
        {
            delete next;
            this -> next = NULL;
        }
        cout << "Deleted " <<endl;
    }
};

Node* create()
{
    int n;

    Node* head = new Node();
    Node* temp = head;

    cout << "Enter the no. of nodes: " <<endl;
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cout << "Enter the value: ";
        cin >> temp -> data;

        if(i == n)
            temp -> next = NULL;
        else
            temp -> next = new Node();

        temp = temp -> next;
    }

    return head;
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

Node* insertathead(Node* head)
{
    Node* newNode = new Node();

    cout << "Enter the value: ";
    cin >> newNode -> data;

    newNode -> next = head;
    head = newNode;

    return head;

}

Node* insertattail(Node* head)
{
    Node* newNode = new Node();
    Node* temp = head;

    cout << "Enter the value: ";
    cin >> newNode -> data;

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = newNode;
    newNode -> next = NULL;

    return head;
    
}

Node* insertatpos(Node* head)
{
    int data;
    Node* temp = head;
    Node* newNode = new Node();

    cout << "Enter the data after which you want to insert: ";
    cin >> data;

    while(temp -> data != data)
    {
        temp = temp -> next;
    }

    cout << "Enter the new data: ";
    cin >> newNode -> data;

    newNode -> next = temp -> next;
    temp -> next = newNode;

    return head;

}

Node* deleteathead(Node* head)
{
    Node* temp = head;
    head = head -> next;

    temp -> next = NULL;

    delete temp;

    return head;
}

Node* deleteattail(Node* head)
{
    Node* temp = head;

    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }

    Node* tempdel = temp -> next;

    temp -> next = NULL;

    delete tempdel;

    return head;
}

Node* deleteatpos(Node* head)
{
    int data;

    cout << "Enter the data of the Node: ";
    cin >> data;

    Node* temp = head -> next;
    Node* prev = head;

    while(prev -> data != data && temp -> data != data)
    {
        prev = prev -> next;
        temp = temp -> next;
    }

    prev -> next = temp -> next;
    temp -> next = NULL;
    delete temp;

    return head;

}

int main()
{
    Node* node1 = new Node();
    Node* head = node1;

    int ch;

    do
    {
        cout << "1. Create a Linked List " <<endl;
        cout << "2. Insert at head " <<endl;
        cout << "3. Insert at tail " <<endl;
        cout << "4. Insert at any position " <<endl;
        cout << "5. Delete at head " <<endl;
        cout << "6. Delete at tail " <<endl;
        cout << "7. Delete in any position " <<endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;

        cin >> ch;

        switch(ch)
        {
            case 1: head = create();
            print(head);
            break;

            case 2: head = insertathead(head);
            print(head);
            break;

            case 3: head = insertattail(head);
            print(head);

            case 4: head = insertatpos(head);
            print(head);
            break;
            
            case 5: head = deleteathead(head);
            print(head);
            break;

            case 6: head = deleteattail(head);
            print(head);
            break;

            case 7: head = deleteatpos(head);
            print(head);
            break;
        }
    } while (ch != 8);
    


    return 0;
}
