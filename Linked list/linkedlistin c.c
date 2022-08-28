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

void insertatend(struct Node* head) 
{
    struct Node* temp = head;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    printf("Enter the value to be inserted at the end: ");
    scanf("%d",&newnode->data);

    temp->next = newnode;
    temp = newnode;
    temp ->next = NULL;

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

void insertbeforenode(struct Node* head)
{
    struct Node* temp = head;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    int key;

    printf("Enter the position of the node so that a value can inserted before it: ");
    scanf("%d",&key);

    while(temp->next->key != key)
    {
        temp = temp->next;
    }

    printf("Enter the value to be inserted: ");
    scanf("%d",&newnode -> data);

    newnode -> next = temp -> next;
    temp -> next = newnode;
    temp = newnode;
}

void insertafternode(struct Node* head)
{
    struct Node* temp = head;
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));

    int key;

    printf("Enter the key after which a value wil be inserted: ");
    scanf("%d",&key);

    while(temp -> next -> key <= key)
    {
        temp = temp -> next;
    }

    printf("Enter the value: ");
    scanf("%d",&newnode -> data);

    newnode -> next = temp-> next;
    temp -> next = newnode;
    temp = newnode;
}

struct Node* deleteathead(struct Node* head)
{
    struct Node* temp = head;

    if(temp -> next == NULL)
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

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = node1;

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
        printf("10. Exit\n");
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
            deleteatend(head);
            print(head);
            break;
        }
    } while (ch != 10);

    return 0;
}
