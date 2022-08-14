// Approach 2

Node* getmiddle(Node* head)
{
    //case 1 and 2 = empty list and only one node is present
    
    if(head == NULL || head -> next == NULL)
        return head;
    
    //Our alogrithm
    
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
            fast = fast -> next;
        slow = slow -> next;
    }
    return slow;
}





/*  Approach 1 */
/*
int getlength(Node *head)
{
    int len = 0;
    
    while(head != NULL)
    {
        len++;
        head = head -> next;
    }
    return len;
}
*/

Node *findMiddle(Node *head) {
    // Write your code here
    return getmiddle(head);
    
    /*
    int len = getlength(head);
    int ans = len / 2;
    
    Node *temp = head;
    int cnt = 0;
    while(cnt < ans)
    {
        temp = temp -> next;
        cnt++;
    }
    return temp;
    */
}
