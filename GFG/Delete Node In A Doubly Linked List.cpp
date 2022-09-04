class Solution
{
    public:
    Node* deleteNode(Node *head, int x)
    {
        if(x == 1)
        {
            head = head -> next;
            head -> prev = NULL;
            return head;
        }
        
        
            Node* temp = head;
            
            for(int i = 0; i < x-1 && temp != NULL; i++)
            {
                temp = temp -> next;
            }
            
            temp -> prev -> next = temp -> next;
            delete temp;
            return head;
            
        
      
    }
};
