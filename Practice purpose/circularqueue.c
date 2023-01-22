#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;

void push()
{
    int item;

    printf("Enter item: ");
    scanf("%d",&item);

    if((front == 0 && rear == n - 1) || (rear == (front - 1) % (n - 1)))
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1 && rear == -1)
    {
        front = 0; 
        rear = 0;
    }
    else if(rear == n - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = item;
    printf("Item pushed\n");
}

void pop()
{
    if(front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return;
    }

    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
    printf("Item Popped\n");
}
void display()
{
    if(front == -1 && rear == -1)
    {
        printf("Nothing to display\n");
        return;
    }
    else
    {
        for(int i = front; i <= rear; i++)
        {
            printf("%d ",queue[i]);
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