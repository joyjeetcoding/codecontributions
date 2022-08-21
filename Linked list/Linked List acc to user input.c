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

struct Node *reverse(struct Node *head)
{
    struct Node *prev = (struct Node *)malloc(sizeof(struct Node));
    struct Node *curr = head;

    prev = NULL;

    while (curr != NULL)
    {
        struct Node *forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

struct Node *solve(struct Node *head, struct Node *head2)
{
    // if the first node contains single element then connect the 1st node to the 2nd one
    if (head->next == NULL)
    {
        head->next = head2;
    }

    struct Node *curr1 = head;
    struct Node *next1 = curr1->next;
    struct Node *curr2 = head2;
    struct Node *next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL)
    {
        if ((curr1->data <= curr2->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        }

        else
        {
            curr1 = next1;
            next1 = next1->next;
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return head;
            }
        }
    }
    return head;
}

struct Node *merge(struct Node *head, struct Node *head2)
{
    if (head == NULL)
        return head2;
    if (head2 == NULL)
        return head;

    if (head->data <= head2->data)
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
        printf("\n");
        printf("1. Create a Linked List\n");
        printf("2. Reverse the Linked List\n");
        printf("3. Merge two Sorted Linked Lists\n");
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
            head2 = create();
            merge(head, head2);
            print(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Wrong Choice\n");
            break;
        }
    } while (ch != 4);

    return 0;
}
