#include <stdio.h>
#define size 5
int top = -1;
int stk[size];

void push()
{
    int n;
    if (top == size - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &n);
        top++;
        stk[top] = n;
        printf("Element pushed\n");
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow\n");
    }
    else
    {
        top--;
        printf("Element popped\n");
    }
}

void display()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stk[i]);
    }
    printf("\n");
}

void peek()
{
    printf("The top element is %d", stk[top]);
    printf("\n");
}

int main()
{
    int n;
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