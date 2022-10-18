#include<iostream>
#define n 5
int front = -1;
int rear = -1;
int deque[n];
using namespace std;

bool isFull()
{
    if((front == 0 && rear == n - 1) || ((rear == front - 1) % (n - 1)))
        return true;
    else
        return false;
}

bool isEmpty()
{
    if(front == -1)
        return true;
    else
        return false;
}

void push_rear()
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(isFull())
    {
        cout << "Queue is full " << endl;
    }

    else if(front == -1 && rear == -1)  //first element push
    {
        front = 0;
        rear = 0;
    }

    else if(front != 0 && rear == n - 1) //cyclic nature
        rear = 0;

    else // normal flow
        rear++;

    deque[rear] = data;

}

void pop_front()
{
    if (front == -1) {
      cout<<"Queue Underflow\n";
      return ;
   }
   cout<<"Element deleted from queue is : "<<deque[front]<<endl;

   if (front == rear) {
      front = -1;
      rear = -1;
   } else {
      if (front == n - 1)
      front = 0;
      else
      front = front + 1;
   }
}

void display()
{
    int f = front, r = rear;
    if(front == -1)
    {
        cout << "Nothing to display" << endl;
        // return;
    }
    // cout << "Queue elements are: " << endl;
    else if(f <= r)
    {
        while (f <= r)
        {
            cout << deque[f] << " ";
            f++;
        }
    }
    else
    {
        while(f <= n-1)
        {
            cout << deque[f] << " ";
            f++;
        }


        f = 0;

        while(f <= r)
        {
            cout << deque[f] << " ";
            f++;
        }
        
    }
    cout << endl;
    
}

void push_front()
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(isFull())
    {
        cout << "Queue is full" << endl;
    }

    else if(front == -1) //single element
    {
        front = 0;
        rear = 0;
    }
    else if(front == 0 && rear != n-1) //cyclic nature
    {
        front = n - 1;
    }

    else    //normal flow
        front--;

    deque[front]=data;
}

void pop_rear()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    
    cout << "Deleted element is " << deque[rear] << endl;
    
    if(front == rear)      //single element
    {
        rear = -1;
        front = -1;
    }

    else if(rear == 0)  //cyclic nature
    {
        rear = n - 1;
    }
    else
        rear--;
}

int main()
{
    int ch;

    do
    {
        cout << "1. Push_front()" << endl;
        cout << "2. Pop_front()" << endl;
        cout << "3. Push_rear()" << endl;
        cout << "4. Pop_rear()" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
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

        case 4: pop_rear();
        break;

        case 5:
            display();
            break;
        

        case 6:
        break;
        
        default: cout << "Wrong Choice" << endl;
        break;
        }

    } while (ch != 6);
    return 0;
}