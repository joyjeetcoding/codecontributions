Node* floydDetectionLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL)
    {
        fast = fast -> next;

        if(fast != NULL)
            fast = fast -> next;

        slow = slow -> next;

        if(slow == fast)
        {
            cout << " Loop Present at " << slow -> data << endl;
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNodeofloop(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }

    Node* intersection = floydDetectionLoop(head);
    Node* slow = head;

    while(slow != intersection)
    {
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}