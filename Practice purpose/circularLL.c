#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node *createDoubly()
{
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data: "); 
        scanf("%d", &temp -> data);

        if(head == NULL)
        {
            head = temp;
            tail = temp;
            tail -> next = head;
        }

        else
        {
            tail -> next = temp;
            tail = temp;
            tail -> next = head;
        }

    }
    return head;
}

void print(struct Node *head)
{
    struct Node *temp = head;

    do
    {
        printf("%d ",temp->data);
        temp = temp -> next;
    } while (temp != head);
    printf("\n");
}

struct Node* insertatbeg(struct Node* head)
{
    struct Node* temp2 = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&temp -> data);

    while(temp2 -> next != head)
    {
        temp2 = temp2 -> next;
    }

    temp -> next = head;
    head = temp;

    temp2 -> next = head;

    return head;
}

struct Node* insertatmid(struct Node* head)
{
    struct Node* temp2 = head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    int n;

    printf("Enter the node data after which you want to insert: ");
    scanf("%d", &n);

    while(temp2 -> data != n)
    {
        temp2 = temp2 -> next;
    }

    printf("Enter the data: ");
    scanf("%d", &temp -> data);

    temp -> next = temp2 -> next;
    temp2 -> next = temp;

    return head;
    
}

struct Node* insertatend(struct Node* head)
{
    struct Node* temp = head;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter the data: ");
    scanf("%d", &newNode -> data);

    while(temp -> next != head)
    {
        temp = temp -> next;
    }
    newNode -> next = head;
    temp -> next = newNode;

    return head;
}

struct Node* delbeg(struct Node* head)
{
    struct Node* temp = head;
    struct Node* tail = head;


    while(tail -> next != head)
    {
        tail = tail -> next;
    }
    head = head -> next;
    tail -> next = head;

    temp -> next = NULL;
    free(temp);

    return head;
}

struct Node* delmid(struct Node* head)
{
    struct Node* temp = head;
    struct Node* temp2 = head -> next;
    int n;

    printf("Enter the no. that you want to delete: ");
    scanf("%d",&n);

    while(temp2 -> data != n)
    {
        temp2 = temp2 -> next;
        temp = temp -> next;
    }

    temp -> next = temp2 -> next;
    temp2 -> next = NULL;

    free(temp2);


    return head;
}

struct Node* delend(struct Node* head)
{
    struct Node* temp = head;

    while(temp -> next -> next != head)
    {
        temp = temp -> next;
    }

    struct Node* temp2 = temp -> next;

    temp -> next = head;
    temp2 -> next = NULL;

    free(temp2);

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));

    int ch;

    do
    {
        printf("1. Create Circular LL \n");
        printf("2. Insert at beginning in Circular LL \n");
        printf("3. Insert at a given position in Circular LL \n");
        printf("4. Insert at end in Circular LL \n");
        printf("5. Delete at beginning \n");
        printf("6. Delete a given node \n");
        printf("7. Delete at end \n");
        printf("8. Exit \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = createDoubly();
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