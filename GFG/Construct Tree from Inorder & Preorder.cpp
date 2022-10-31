class Solution{
    public:
    
    void creatMapping(int in[],int n,map<int,int>&m)
    {
        for(int i = 0;i<n;i++)
        {
           m[in[i]] = i;
        }
    }

    Node*solve(int in[],int pre[],int &index,int start,int end,int n,map<int,int>&m)
    {
        //base case
        if(index >=n || start>end)
        {
            return NULL;
        }

        //create a root node for element
        int element = pre[index++];
        Node*root = new Node(element);
        
        //find element's index inorder
        int pos = m[element];

        root->left = solve(in,pre,index,start,pos-1,n,m);
        root->right = solve(in,pre,index,pos+1,end,n,m);
        
        return root;
    }

    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int>m;
        creatMapping(in,n,m);
        int preorderindex = 0;
        
        Node*ans = solve(in,pre,preorderindex,0,n-1,n,m);

        return ans;
    }


};
