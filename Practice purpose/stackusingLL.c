#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* top;

void push()
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("Overflow");
    }
    else
    {
        printf("Enter data: ");
        scanf("%d", &newNode -> data);

        newNode -> next = top;
        top = newNode;
    }
}

void display()
{
    struct Node* temp = top;

    while(temp != NULL)
    {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    
    printf("\n");

}

void pop()
{
    struct Node* temp = top;

    if(top == NULL)
    {
        printf("Underflow\n");
    }
    else
    {
        top = top -> next;
        temp -> next = NULL;
        free(temp);
        printf("Item popped\n");
    }
}

void peek()
{
    printf("The top element is %d\n",top -> data);
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    int ch;

    do
    {
        /* code */

        printf("1. Push()\n");
        printf("2. Pop()\n");
        printf("3. Peek()\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            push();
            display();
            break;

        case 2:
            pop();
            display();
            break;

        case 3:
            peek();
            break;

        case 4:
            break;

        default:
            printf("Wrong choice\n");
            break;
        }

    } while (ch != 4);
    return 0;
}