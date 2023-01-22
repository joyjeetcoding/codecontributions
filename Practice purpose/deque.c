#include <stdio.h>
#include<stdbool.h>
#define n 5
int deque[n];
int front = -1;
int rear = -1;

bool isFull()
{
    if((front == 0 && rear == n - 1) || (rear == (front - 1)%(n-1)))
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(front == -1 && rear == -1)
        return true;
    else
        return false;
}

void push_front()
{
    int item;
    printf("Enter the no. ");
    scanf("%d", &item);
    if(isFull())     //Full condition
    {
        printf("Overflow\n");
        return;
    }

    else if(isEmpty())      //1st element insert
    {
        front = 0;
        rear = 0;
    }

    else if(front == 0 && rear != n-1)  //cyclic nature
    {
        front = n - 1;
    }

    else
    {
        front++;
    }

    deque[rear] = item;
    printf("Value inserted\n");

}

void push_rear()
{
    int item;
    printf("Enter the no. ");
    scanf("%d", &item);

    if (front == 0 && rear == n - 1) // full condition
    {
        printf("Overflow\n");
        return;
    }

    else if (front == -1 && rear == -1) // 1st element
    {
        front = 0;
        rear = 0;
    }

    else if(front != 0 && rear == n-1)  //cyclic nature
        rear = 0;

    else // normal flow
    {
        rear++;
    }

    deque[rear] = item;
    printf("Value inserted\n");
}

void pop_front()
{
    if(isEmpty())
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

void pop_rear()
{
    if(isEmpty())
    {
        printf("Unerflow\n");
        return;
    }
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
    {
        rear--;
    }
    printf("Item Popped\n");

}

void display()
{
    if(isEmpty())
    {
        printf("Nothing to display\n");
        
    }
    else if(front <= rear)
    {
        while(front <= rear)
        {
            printf("%d ",deque[front]);
            front++;
        }
    }

    else
    {

    }

}



int main()
{
    int ch;
    do
    {
        printf("1. Push_front in deque\n");
        printf("2. Pop_front in deque\n");
        printf("3. Push_rear in deque\n");
        printf("4. Pop_rear in deque\n");
        printf("5. Display deque\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push_front();
            break;

        case 2:
            pop_front();
            break;

        case 3:
            push_rear();
            break;

        case 4:
            pop_rear();
            break;

        case 5:
            display();
            break;
        default:
            break;
        }
    } while (ch != 6);

    return 0;
}