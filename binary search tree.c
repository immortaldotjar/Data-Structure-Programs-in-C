#include <stdio.h>
#include <stdlib.h>

// node for tree
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

// Insert into Binary search tree
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

// Searching the value in tree
struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() 
{
    struct Node* root = NULL;

    int key,n,i,value;
    char ch;
    
    while(1)
    {
        printf("\nDo you want to enter the menu? [Y/n]: ");
        scanf(" %c",&ch); 

        //checking condition for YES
        if (ch == 'Y' || ch == 'y') 
        {
            printf("\nEnter the number of Values to be inserted in Tree : ");
            scanf("%d",&n);

            for(i = 0;i < n;i++)
            {
                printf("Enter value %d : ",i+1);
                scanf("%d",&value);

                root = insert(root,value);
            }

            printf("\nEnter the value to Search in the Tree : ");
            scanf("%d",&key);

            struct Node* found = search(root, key);

            if (found)
            {
        
                printf("Found %d in the Tree!\n", key);
            }
            else
            {
                printf("%d was not found in the Tree!\n", key);
            }
        }
        else 
        {
            printf("Exiting...\n");
            break;
        }
    }
    return 0;
}
