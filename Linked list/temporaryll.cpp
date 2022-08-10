#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
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
class Node* create()
{
    Node *head = new Node();
    Node *temp = head;
    int n;
    cout << "Enter the no. of nodes " << endl;
    cin >> n;

    cout << "Enter the values " << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp->data;
        if (i == n)
        {
            temp->next = NULL;
        }
        else
        {
            temp->next = new Node;
        }
        temp = temp->next;
    }
    return head;
}

void insertattail(Node *&tail, int d)
{
    Node *temp = new Node();
    temp->data = d;
    tail->next = temp;
    tail = temp;

    
}

int main()
{
    Node *node1 = new Node();
    Node *tail = node1;
    Node *head = node1;

    int d, ch, n;
    cout << " Enter your choice " << endl;
    cout << " Create Linked List " << endl;
    cout << " Insertion at head " << endl;
    cout << " Insertion at tail " << endl;
    cout << " Insertion at any position " << endl;
    cin >> ch;
    switch (ch)
    {
    case 1:
        head = create();
        print(head);
        break;
    // case 2:
    //     break;
    // case 2: insertathead();
    // break;
    case 3:
        cout << "Enter the no. of nodes " << endl;
        cin >> n;

        cout << "Enter the values " << endl;
        for(int i = 0; i < n; i++)
        {
            cin >> d;
            insertattail(head, d);
        }
        print(head);
        break;
    // case 4: insertatanyposition();
    // break;
    // case 0:
    // break;
    default:
        cout << " Wrong Choice" << endl;
        break;
    }

    return 0;
}
