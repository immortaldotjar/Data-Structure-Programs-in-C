#include <stdio.h>
#include <stdlib.h>

// Node for Tree
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Inserting value in tree
struct Node* insert(struct Node* root, int value) 
{
    if(root == NULL)
    {
        return createNode(value);
    }
    else
    {
        if(value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if(value > root->data)
        {
            root->right = insert(root->right, value);
        }
        return root;

    }
}

// Inorder Traversal (sorted order)
void inorder(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Preorder Traversal
void preorder(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);

    }
}
// Postorder Traversal
void postorder(struct Node* root) 
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);

    }
}

int main() 
{
    struct Node* root = NULL;
    int n, i, value;
    char ch;

    while (1) 
    {
        printf("\nDo you want to insert elements into the tree? [Y/n]: ");
        scanf(" %c", &ch);

        //checking condition for YES
        if (ch == 'Y' || ch == 'y') 
        {
            printf("\nEnter the number of values to be inserted in Tree: ");
            scanf("%d", &n);
            
            for (i = 0; i < n; i++) 
            {
                printf("Enter value %d: ", i + 1);
                scanf("%d", &value);
                root = insert(root, value);
            }

            printf("\nInorder traversal:\n");
            inorder(root);
            printf("\n");

            printf("Preorder traversal:\n");
            preorder(root);
            printf("\n");

            printf("Postorder traversal:\n");
            postorder(root);
            printf("\n");

        } 
        else 
        {
            printf("Exiting...\n");
            break;
        }
    }
    return 0;
}
