#include<iostream>
using namespace std;

int getSum(int arr[],int size)
{
    // base case
    if(size == 0)
        return 0;
    if(size == 1)
        return arr[0];

    
    
    int restpart = getSum(arr+1, size-1);
    int sum = arr[0] + restpart;
    return sum;

}

int main()
{
    int arr[5] = {3,2,5,1,6};
    int size = 5;

    int ans = getSum(arr,size);
    
    cout << "Sum is " << ans << endl;
    return 0;
}
