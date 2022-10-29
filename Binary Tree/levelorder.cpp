#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

//building a tree
Node* buildtree(Node* root)
{
    cout << " Enter Data: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data for inserting in left of "<<data << endl;
    root -> left = buildtree(root -> left);

    cout << "Enter data for inserting in right of "<< data << endl;
    root -> right = buildtree(root -> right);

    return root;
}

//Level order traversal

void levelordertraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp -> data << " ";
        q.pop();

        if(temp -> left)
        {
            q.push(temp -> left);
        }
        if(temp -> right)
        {
            q.push(temp -> right);
        }
    }
}

int main()
{
    Node* root = NULL;

    //buildingtree
    root = buildtree(root);

    //level order
    // 1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1
    cout << "Level order Traversal is: ";
    levelordertraversal(root);
    
    return 0;
}