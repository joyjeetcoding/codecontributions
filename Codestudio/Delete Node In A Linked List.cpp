void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    
    LinkedListNode<int>* prev = node;
    LinkedListNode<int>* curr = prev -> next;
    
    prev -> data = curr -> data;
    prev -> next = curr -> next;
    curr -> next = NULL;
    
    delete curr;
}
