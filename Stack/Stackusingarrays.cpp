#include <iostream>
using namespace std;

class Stack
{
public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    bool isEmpty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(int size)
    {
        int element;
        for(int i = 1; i <= size; i++)
        {

        cout << "Enter the element: " <<endl;
        cin >> element;
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "Stack overflow" << endl;
        }
        }
    }

    void pop()
    {
        if (isEmpty())
            cout << "Stack underflow" << endl;
        else
            top--;
            cout << "Item popped" <<endl;
    }

    void display()
    {
        if(isEmpty())
        {
            cout << "Stack is Empty" <<endl;
        }
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int peek()
    {
        if (top >= 0)
            return arr[top];

        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
    }
};

int main()
{
    Stack st(1000);
    int n, ch;

    do
    {

        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout <<"Enter your Choice: " <<endl;
        cin >> ch;
        switch(ch)
        {
            case 1:
            cout <<"Enter the size: ";
            cin >> n;
            st.push(n);
            break;

            case 2: st.pop();
            break;
            case 3: st.display();
            break;

            case 4: 
            break;
            default:
            cout << "Wrong choice" << endl;
        }
    } while (ch!=4);
    return 0;
}
