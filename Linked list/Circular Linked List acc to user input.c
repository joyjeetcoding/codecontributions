#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* head = NULL;
struct Node* tail = NULL;

struct Node *circularLL()
{
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d",&temp -> data);

        if(head == NULL)
        {
            head = temp;
            tail = temp;
            temp -> next = head;
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

struct Node* delbeg(struct Node* head, struct Node *tail)
{
    struct Node* temp;

    if(head == NULL)
        return NULL;
    else if(head -> next == head)
    {
        head = NULL;
        free(head);
    }
    temp = head;

    tail -> next = head -> next;

    free(temp);
    head = tail -> next;
    return head;
}

void print(struct Node *head)
{
    struct Node *temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = node1;

    int ch;
    do
    {
        printf("1. Create a Circular Linked List\n");
        printf("2. Delete a node at the beginning\n");
        printf("3. Delete a node at the end\n");
        printf("4. Delete a node of a given index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = circularLL(head);
            print(head);
            break;

        case 2:
            head = delbeg(head, tail);
            print(head);
            break;

        }
    } while (ch != 5);

    return 0;
}
