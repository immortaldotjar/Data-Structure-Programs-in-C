#include <stdio.h>
 #include <stdlib.h>

// Define the structure for a node
struct Node 
{ 
    int data; 
    struct Node* next; 
};

// Function to insert a node at the beginning 
void insertAtBeginning(struct Node** head, int value)
{ 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value; 
    newNode->next = *head;
    *head = newNode; 
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int value, int pos) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If inserting at the head (position 1)
    if (pos == 1) 
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    else
    {
        struct Node* temp = *head;
        for (int i = 1; temp != NULL && i < pos - 1; i++) 
        {
            temp = temp->next;
        }

        // If position is out of bounds
        if (temp == NULL) 
        {
            printf("Position out of range\n");
            free(newNode);
            return;
        }
        else
        {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

// Function to delete a node from the beginning of the list
void deleteAtBeginning(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted from the beginning.\n");
    }
}

// Function to delete a node from the end of the list
void deleteAtEnd(struct Node** head) 
{
    if (*head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) 
    {
        free(*head);
        *head = NULL;
        printf("Last node deleted.\n");
        return;
    }
    else
    {
        struct Node* temp = *head;
        while (temp->next->next != NULL) 
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
        printf("Node deleted from the end.\n");
    }
}

// Function to delete a node at a specific position
void deleteAtPosition(struct Node** head, int pos)
{
    if (*head == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        struct Node* temp = *head;

        if (pos == 1)
        {
            *head = temp->next;
            free(temp);
            printf("Node deleted from position 1.\n");
            return;
        }

        for (int i = 1; temp != NULL && i < pos - 1; i++)
        {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL)
        {
            printf("Position out of range\n");
            return;
        }

        struct Node* next = temp->next->next;
        free(temp->next);
        temp->next = next;
        printf("Node deleted from the position %d.\n", pos);
    }
}

// Function to display the linked list
void Display(struct Node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty!\n");
        return;
    }
    else
    {
        struct Node* temp = head;
        printf("Linked List: \n");
        printf("[ ");
        while (temp != NULL) 
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL ]\n");
    }
}

int main() 
{ 
    struct Node* head = NULL;

    int ch,value,pos;
    char op;

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]): ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Insert element at the start\n2. Insert element at the end\n3. Insert element at the Specific Position\n4. Delete element from start\n5. Delete element from end\n6. Delete element from Specific Position\n7. Display the List\n8. Exit from Menu\n\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch (ch) 
            {
                case 1:
                    printf("Enter the value : ");
                    scanf("%d",&value);

                    insertAtBeginning(&head,value);
                    break;
                case 2:
                    printf("Enter the value : ");
                    scanf("%d",&value);

                    insertAtEnd(&head,value);
                    break;
                case 3:
                    printf("Enter the value : ");
                    scanf("%d",&value);

                    printf("Enter the position : ");
                    scanf("%d",&pos);
                    insertAtPosition(&head,value,pos);
                    break;
                case 4:
                    deleteAtBeginning(&head);
                    break;
                case 5:
                    deleteAtEnd(&head);
                    break;
                case 6:
                    printf("Enter the position : ");
                    scanf("%d",&pos);

                    deleteAtPosition(&head,pos);
                    break;
                case 7:
                    Display(head);
                    break;
                case 8:
                    printf("Exiting...");
                    exit(0);
                default:
                    printf("Entered wrong choice!\n");
                    break;
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
