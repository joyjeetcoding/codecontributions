#include <bits/stdc++.h> 
class CircularQueue{
    int* arr;
    int size;
    int rear;
    int front;
    
    public:
    // Initialize your data structure.
    CircularQueue(int n){
        // Write your code here.
        size = n;
        arr = new int[n];
        rear = -1;
        front = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // Write your code here
        //t check whether the queue is full or not
        if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
           {
//                cout << "Queue is full" << endl;
               return false;
           }
           else if(front == -1)    //inserting first element
           {
               front = rear = 0;
           }
           
           else if(rear == size - 1 && front != 0)
           {
               rear = 0;    //to maintain cyclic nature
           }
           
           else
           {    //normal flow
               rear++;
           }
           arr[rear] = value;    //pushing inside th queue
           return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // Write your code here.
        
        if(front == -1)
        {
//             cout << "Queue is empty" << endl;
            return  -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if(front == rear)    //for single element
        {
            front = rear = -1;
        }
        else if(front == size - 1)
        {
            front = 0;    //to maintain cyclic nature
        }
        else    //normal flow
            front++;
        return ans;
    }
};