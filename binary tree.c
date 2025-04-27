#include <stdio.h>
#include <stdlib.h>
// Structure for a tree node
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-order traversal (Left -> Root -> Right)
void inorderTraversal(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorderTraversal(root->left);
        printf("%d\t", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order traversal (Root -> Left -> Right)
void preorderTraversal(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order traversal (Left -> Right -> Root)
void postorderTraversal(struct Node* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d\t", root->data);
    }
    
}

// Main function to test
int main() {
    // Manually creating a simple binary tree:
    /*
             1
            / \
           2   3
          / \
         4   5
    */

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal :\n");
    inorderTraversal(root);
    printf("\n");

    printf("Preorder traversal :\n");
    preorderTraversal(root);
    printf("\n");

    printf("Postorder traversal :\n");
    postorderTraversal(root);
    printf("\n");

    return 0;

}
