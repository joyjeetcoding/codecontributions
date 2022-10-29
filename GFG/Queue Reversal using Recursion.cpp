void reverse(queue<int> &q, int element)
{
    //base case
    if(q.empty())
    {
        q.push(element);
        return;
    }
        
    int element2 = q.front();
    q.pop();
    
    reverse(q, element2);
    q.push(element);
}


queue<int> rev(queue<int> q)
{
    // add code here.
    
    int element = q.front();
    q.pop();
    reverse(q, element);
    
    
    return q;
    
    
}
