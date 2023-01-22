#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;

void push()
{
    int item;
    printf("Enter the no. ");
    scanf("%d", &item);

    if (rear == n - 1) // full condition
    {
        printf("Overflow\n");
        return;
    }

    else if (front == -1 && rear == -1) // empty condition
    {
        front = 0;
        rear = 0;
    }

    else // normal flow
    {
        rear++;
    }

    queue[rear] = item;
    printf("Value inserted\n");
}

void pop()
{
    if (front == -1) // empty condition
    {
        printf("Queue Underflow\n");
        return;
    }

    else if (front == rear) // full condition
    {
        front = -1;
        rear = -1;
    }
    else // normal flow
    {
        front++;
    }
    printf("Item popped\n");
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Nothing to display\n");
    }
    else
    {

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
    }
}

int main()
{
    int ch;
    do
    {
        printf("1. Push in queue\n");
        printf("2. Pop in queue\n");
        printf("3. Display queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;
        default:
            break;
        }
    } while (ch != 4);

    return 0;
}