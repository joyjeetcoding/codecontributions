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

Node* insertintoBST(Node* root, int data)
{
    //base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(data > root -> data)
    {
        //right part mein insert karna hai
        root -> right = insertintoBST(root -> right, data);
    }
    else
    {
        //left part insert hoga

        root->left = insertintoBST(root -> left, data);
    }

    return root;
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);  //separator daal diya kyu ki root node mein sirf ek hi element rehta hai

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child nodes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

void takeinput(Node* &root)
{
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertintoBST(root, data);
        cin >> data;
    }
}

void inorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    inorder(root -> left);
    cout << root -> data <<" ";
    inorder(root -> right);
}

void preorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    cout << root -> data <<" ";
    preorder(root -> left);
    preorder(root -> right);
}

void postorder(Node* root)
{
    //base case
    if(root == NULL)
        return;

    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data <<" ";
}

Node* deleteFromBST(Node* root, int val)
{
    // base case
    if(root == NULL)
        return;

    if(root -> data == val)
    {
        // 0 child
        if(root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 Child
        //left child

        if(root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // right child
        if(root -> left == NULL && root -> right != NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }



        // 2 Child
        if(root -> left != NULL && root -> right != NULL)
        {
           

        }

    }

    else if(root -> data > val)
    {
        // left part
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }

    else
    {
        // right part
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main()
{
    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeinput(root);

    cout << endl;
    cout << "Printing the BST..." << endl;
    levelOrderTraversal(root);

    cout << endl;
    cout << "Printing the BST inorder..." << endl;
    inorder(root);

    cout << endl;
    cout << "Printing the BST preorder..." << endl;
    preorder(root);
 
    cout << endl;
    cout << "Printing the BST postorder..." << endl;
    postorder(root);

    return 0;
}