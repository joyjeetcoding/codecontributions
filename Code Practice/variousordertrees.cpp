#include<iostream>
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

Node* buildTree(Node* root)
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data for the left of "<< data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data for the right of "<< data << endl;
    root -> right = buildTree(root -> right);

    return root;

}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";
}

int main()
{
    Node* root = NULL;

    root = buildTree(root);

    cout << endl;

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 

    cout << "Inorder Traversal is " << endl;
    inorder(root);

    cout << endl;

    cout << "Preorder Traversal is " << endl;
    preorder(root);

    cout << endl;

    cout << "Postorder Traversal is " << endl;
    postorder(root);
    return 0;
}