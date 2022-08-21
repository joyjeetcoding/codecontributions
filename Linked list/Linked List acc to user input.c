#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *create()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &temp->data);

        if (i == n)
            temp->next = NULL;
        else
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
        }
        temp = temp->next;
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

struct Node* reverse(struct Node* head)
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

int main()
{
    struct Node *node1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *head = node1;
    int ch;

    do
    {
        printf("\n");
        printf("1. Create a Linked List\n");
        printf("2. Reverse the Linked List\n");
        printf("3. Merge two Linked Lists\n");
        printf("4. Exit\n");
        printf("Enter you choice:\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            head = create();
            print(head);
            break;
        case 2:
            head = reverse(head);
            print(head);
            break;
        case 3:
            head = create();
            // merge(head);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (ch != 4);

    return 0;
}
