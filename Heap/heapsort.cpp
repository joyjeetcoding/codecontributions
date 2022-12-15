#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int size = n;

    while(size > 1)
    {
        // Step 1: Swap
        swap(arr[size], arr[1]);
        size--;

        // Step 2:heapify or we can say that we are putting the element in the correct position
        heapify(arr, size, 1);
    }
}

int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    // Heap Creation
    for(int i = n/2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    cout << "Printing the array using heapify algo: "<<endl;
    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Heap Sort
    heapSort(arr, n);
    cout << "Printing the array using heap sort algo: "<<endl;
    for(int i = 0; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}