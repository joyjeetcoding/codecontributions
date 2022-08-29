#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
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

struct Node* mergeunsorted(struct Node* head, struct Node* head2)
{
    struct Node* tail = head;

    while(tail != NULL)
    {
        if(tail -> next == NULL && head2 != NULL)
        {
            tail -> next = head2;
            break;
        }
        tail = tail -> next;
    }
    return head;
}


void sortunsorted(struct Node* head)
{
    struct Node* curr = head;
    struct Node* temp = head;

    while(curr -> next != NULL)
    {
        temp = curr ->next;
        while(temp != NULL)
        {
            if(temp -> data < curr-> data)
            {
                int t = temp->data;
                temp -> data = curr -> data;
                curr -> data = temp -> data;
            }
            temp = temp -> next;
        }
        curr = curr -> next;
    }

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

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = node1;
    struct Node *head2 = node1;


    int ch;

    do
    {
        printf("1. Create a linked list\n");
        printf("2. Sort two unsorted ll\n");
        printf("Enter your choice: ");

        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = createlinkedlist();
            print(head);
            break;
        case 2:
            head2 = createlinkedlist();
            head = mergeunsorted(head,head2);
            sortunsorted(head);
            print(head);
            break;
        case 3: 
            break;
            default:
            printf("Wrong choice");
        }
    } while (ch != 3);
}