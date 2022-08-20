#include <iostream>
using namespace std;

void print(int arr[], int size)
{
    cout << "Size of array is " << size << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool lsearch(int arr[], int size, int key)
{
    print(arr, size);
    // base case
    if (size == 0)
        return false;

    if (arr[0] == key)
        return true;
    else
    {
        bool restpart = lsearch(arr + 1, size - 1, key);
        return restpart;
    }
}

int main()
{
    int arr[5] = {2, 5, 1, 5, 6};
    int size = 5;
    int key = 1;
    bool ans = lsearch(arr, size, key);

    if (ans)
        cout << "Present" << endl;
    else
        cout << "Absent" << endl;
    return 0;
}
