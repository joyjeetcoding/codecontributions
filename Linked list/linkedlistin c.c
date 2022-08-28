#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    int data;
    struct Node *next;
};

struct Node *createlinkedlist()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        temp->key = i;
        printf("Enter the value: ");
        scanf("%d", &temp->data);

        if (i == n)
        {
            temp->next = NULL;
        }

        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
        }
        temp = temp->next;
    }
    return head;
}

struct Node *insertathead(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter a new value to be inserted at head: ");
    scanf("%d", &temp->data);

    temp->next = head;
    head = temp;

    return head;
}

void insertatend(struct Node *head)
{
    struct Node *temp = head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("Enter the value to be inserted at the end: ");
    scanf("%d", &newnode->data);

    temp->next = newnode;
    temp = newnode;
    temp->next = NULL;
}

void print(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertbeforenode(struct Node *head)
{
    struct Node *temp = head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    int key;

    printf("Enter the position of the node so that a value can inserted before it: ");
    scanf("%d", &key);

    while (temp->next->key != key)
    {
        temp = temp->next;
    }

    printf("Enter the value to be inserted: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
    temp = newnode;
}

void insertafternode(struct Node *head)
{
    struct Node *temp = head;
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));

    int key;

    printf("Enter the key after which a value wil be inserted: ");
    scanf("%d", &key);

    while (temp->next->key <= key)
    {
        temp = temp->next;
    }

    printf("Enter the value: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;
    temp = newnode;
}

struct Node *deleteathead(struct Node *head)
{
    struct Node *temp = head;

    if (temp->next == NULL)
    {
        free(temp);
        head = NULL;
    }
    else
    {
        head = temp->next;
        free(temp);
    }

    return head;
}

struct Node* deleteatend(struct Node *head)
{
    struct Node *tail = head;
    struct Node *temp = head;

    if (tail->next == NULL)
    {
        free(tail);
        return tail;
    }

    else
    {

        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        while (temp->next != tail)
        {
            temp = temp->next;
        }

        free(tail);
        tail = temp;
        tail -> next = NULL;

    }
    return tail;
}

void deletebeforenode(struct Node* head)
{
    struct Node* tail = head;
    struct Node* temp = head;

    int key;

    printf("Enter the key value so that the previous nde can be deleted: ");
    scanf("%d",&key);

    while(tail -> next -> key != key)
    {
        temp = tail;
        tail = tail -> next;
    }
    temp -> next = tail->next;
    free(tail);

}

void deleteafternode(struct Node* head)
{
    struct Node* tail = head;
    struct Node* temp = head;

    int key;
    printf("Enter the node after which the next node will be deleted: ");
    scanf("%d",&key);

    while(temp ->next -> key <= key)
    {
        temp = temp -> next;
        tail = temp -> next;
    }

    temp -> next = tail -> next;
    free(tail);
}

struct Node* reversell(struct Node* head)
{
    struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = head;

    prev = NULL;

    while(curr != NULL)
    {
        struct Node* forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

struct Node* solve(struct Node* head, struct Node* head2)
{
    if(head -> next == NULL)
    {
        head -> next = head2;
        return head;
    }
    struct Node* curr1 = head;
    struct Node* next1 = curr1 -> next;
    struct Node* curr2 = head2;
    struct Node* next2 = curr2 -> next;


    while(next1 != NULL && curr2 != NULL)
    {

        if((curr1 -> data <= curr2 -> data) && (curr2 -> data <= next1 -> data))
        {
            curr1 -> next = curr2;
            next2 = curr2 -> next;
            curr2 -> next = next1;

            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            curr1 = next1;
            next1 = next1 -> next;

            if(next1 == NULL)
            {
                curr1 -> next = curr2;
                return head;
            }
        }
    }
    return head;
}

struct Node* mergesortedll(struct Node* head, struct Node* head2)
{
    if(head == NULL)
        return head2;
    if(head2 == NULL)
        return head;

    if(head -> data < head2 -> data)
        return solve(head, head2);
    else
        return solve(head2, head);

}

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = node1;
    struct Node *head2 = node1;


    int ch;

    do
    {
        printf("1. Create a linked list\n");
        printf("2. Insert at head\n");
        printf("3. Insert at end\n");
        printf("4. Insert before a node\n");
        printf("5. Insert after a node\n");
        printf("6. Delete at head\n");
        printf("7. Delete at end\n");
        printf("8. Delete before a node\n");
        printf("9. Delete after a node\n");
        printf("10. Reverse a linked list\n");
        printf("11. Merge two sorted linked list\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = createlinkedlist();
            print(head);
            break;
        case 2:
            head = insertathead(head);
            print(head);
            break;

        case 3:
            insertatend(head);
            print(head);
            break;

        case 4:
            insertbeforenode(head);
            print(head);
            break;

        case 5:
            insertafternode(head);
            print(head);
            break;

        case 6:
            head = deleteathead(head);
            print(head);
            break;

        case 7:
            head = deleteatend(head);
            print(head);
            break;

        case 8: 
            deletebeforenode(head);
            print(head);
            break;

        case 9: 
            deleteafternode(head);
            print(head);
            break;

        case 10: 
            head = reversell(head);
            print(head);
            break;

        case 11:
            head2 = createlinkedlist();
            head = mergesortedll(head, head2);
            print(head);

        case 12:
            break;
        default:
            printf("Wrong choice");
        }
    } while (ch != 12);

    return 0;
}
