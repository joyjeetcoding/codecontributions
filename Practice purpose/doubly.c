#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *createDoubly(struct Node *head)
{
    int n, data;
    struct Node *tail = head;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);

        if (i == 1)
        {
            tail->data = data;
            tail->prev = NULL;
        }

        else if (i == n)
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = NULL;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }

        else
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
    }
    return head;
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

struct Node* insertatbeg(struct Node* head)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&temp -> data);

    temp -> prev = NULL;
    temp -> next = head;
    head -> prev = temp;
    head = temp;

    return head;
}

struct Node* insertatmid(struct Node* head)
{
    int n;
    struct Node* temp1 = head;
    struct Node* temp2 = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data after which you want to insert: ");
    scanf("%d",&n);

    while(temp1 -> data != n)
    {
        temp1 = temp1 -> next;
    }

    printf("Enter the data: ");
    scanf("%d", &temp2 -> data);

    temp2 -> next = temp1 -> next;
    temp1 -> next -> prev = temp2;
    temp1 -> next = temp2;
    temp2 -> prev = temp1;

    return head;
}

struct Node* insertatend(struct Node* head)
{
    struct Node* tail = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    while(tail -> next != NULL)
    {
        tail = tail -> next;
    }

    printf("Enter the data: ");
    scanf("%d", &temp -> data);

    temp -> next = NULL;
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

    return head;
}

struct Node* delbeg(struct Node* head)
{
    struct Node* temp = head;
    head = head -> next;
    head -> prev = NULL;
    temp -> next = NULL;
    temp ->prev = NULL;

    free(temp);

    return head;
}

struct Node* delmid(struct Node* head)
{
    struct Node* temp1 = head;
    struct Node* temp2 = head -> next;
    int n;

    printf("Enter the no. u want to delete: ");
    scanf("%d", &n);

    while(temp2 -> data != n)
    {
        temp2 = temp2 -> next;
        temp1 = temp1 -> next;
    }

    temp1 -> next = temp2 -> next;
    temp2 -> next -> prev = temp1;
    temp2 -> next = NULL;
    temp2 -> prev = NULL;

    free(temp2);

    return head;
}

struct Node* delend(struct Node* head)
{
    struct Node* temp = head;

    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }

    struct Node* temp2 = temp -> next;

    temp -> next = NULL;
    temp2 -> next = NULL;
    temp2 -> prev = NULL;

    free(temp2);

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    int ch;

    do
    {
        printf("1. Create Doubly LL \n");
        printf("2. Insert at beginning in Doubly LL \n");
        printf("3. Insert at a given position in Doubly LL \n");
        printf("4. Insert at end in Doubly LL \n");
        printf("5. Delete at beginning \n");
        printf("6. Delete a given node \n");
        printf("7. Delete at end \n");
        printf("8. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = createDoubly(head);
            print(head);
            break;

        case 2:
            head = insertatbeg(head);
            print(head);
            break;

        case 3:
            head = insertatmid(head);
            print(head);
            break;
        case 4:
            head = insertatend(head);
            print(head);
            break;

        case 5:
            head = delbeg(head);
            print(head);
            break;

        case 6:
            head = delmid(head);
            print(head);
            break;

        case 7:
            head = delend(head);
            print(head);
            break;

        case 8:
            break;
        }
    } while (ch != 8);
    return 0;
}