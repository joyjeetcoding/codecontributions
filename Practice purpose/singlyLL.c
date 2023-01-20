#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createLL()
{
    int n;

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;

    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Enter data: ");
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

struct Node *insertatbeg(struct Node *head)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = head;
    head = newNode;

    return head;
}

struct Node *insertatmid(struct Node *head)
{
    int n;
    struct Node *temp = head;

    printf("Enter the no. after which you want to insert: ");
    scanf("%d", &n);

    while (temp->data != n)
    {
        temp = temp->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct Node *insertatend(struct Node *head)
{
    struct Node *temp = head;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &newNode->data);

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;

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

struct Node *delbeg(struct Node *head)
{
    struct Node *temp = head;

    head = head->next;
    temp->next = NULL;
    free(temp);

    return head;
}

struct Node *delend(struct Node *head)
{
    struct Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    struct Node *deltemp = temp->next;

    temp->next = NULL;

    free(deltemp);

    return head;
}

struct Node *delmid(struct Node *head)
{
    struct Node *temp = head -> next;
    struct Node *prev = head;

    int n;

    printf("Enter the data you want to delete: ");
    scanf("%d", &n);

    while (prev -> data != n && temp -> data != n)
    {
        prev = prev -> next;
        temp = temp->next;
    }

    prev -> next = temp -> next;
    temp -> next = NULL;

    free(temp);

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    int ch;

    do
    {
        printf("1. Create Singly LL \n");
        printf("2. Insert at beginning in Singly LL \n");
        printf("3. Insert at a given position in Singly LL \n");
        printf("4. Insert at end in Singly LL \n");
        printf("5. Delete at beginning \n");
        printf("6. Delete a given node \n");
        printf("7. Delete at end \n");
        printf("8. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = createLL();
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