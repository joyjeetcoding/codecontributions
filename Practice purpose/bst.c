#include <stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
void inorder(struct Node* root)
{
    if(root != NULL)
    {

    inorder(root -> left);
    printf("%d", root -> data);
    inorder(root -> right);
    }
}

struct Node* new_data(int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp -> data = data;
    temp->left = NULL;
    temp -> right = NULL;
    return temp;
}
struct Node* createBST(struct Node* root, int data)
{
    if(root == NULL)
    {
        return new_data(data);
    }
    else if(root -> data > data)
    {
        createBST(root -> left, data);
    }
    else
    {
        createBST(root -> right, data);
    }
    return root;
}



int main()
{
    struct Node *root;
    int data, n;
    printf("Enter the no. of nodes: ");
    scanf("%d", &n);

    printf("Enter the root data: ");
    scanf("%d", &data);
    root = new_data(data);
    printf("Enter other datas: ");

    for(int i = 1; i < n; i++)
    {
        scanf("%d", &data);
        createBST(root, data);
    }

    inorder(root);
    

    return 0;
}