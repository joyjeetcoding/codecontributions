#include<vector>
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        vector<int> arr;
        
        Node* temp = head;
        
        while(temp != NULL)
        {
            arr.push_back(temp -> data);
            temp = temp -> next;
        }
        
        int s = 0;
        int n = arr.size();
        int e = n-1;
        
        while(s <= e)
        {
            if(arr[s] == arr[e])
            {
                s++;
                e--;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};
