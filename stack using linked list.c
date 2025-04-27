#include <stdio.h>
#include <stdlib.h>

//creating New node
struct Node
{
    int data;
    struct Node* next;
};

//For pushing the element in stack
void Push(struct Node** top) 
{
    int value;

    //allocating the size in memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        printf("Heap OVERFLOW!\n");
        return;
    }
    else
    {
        printf("Enter the value : ");
        scanf("%d",&value);

        //assigning the value to the node
        newNode->data = value; 

        //assigning the next address 
        newNode->next = *top;
        *top = newNode;
    }
}

//For popping the element in stack
int Pop(struct Node** top) 
{
    if (*top == NULL) 
    {
        printf("Stack UNDERFLOW!\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedValue = temp->data;

    printf("Popped element : %d\n",poppedValue);
    *top = (*top)->next;

    //for freeing up the memory
    free(temp);
}

//For displaying the element of the stack
void Display(struct Node* top) 
{
    if (top == NULL) 
    {
        printf("Stack UNDERFLOW!\n");
        return;
    }
    else
    {
        struct Node* temp = top;
        printf("Stack elements:\n");

        //displaying the stack
        printf("[ ");
        while (temp != NULL) 
        {
            printf("%d,", temp->data);
            temp = temp->next;

        }
        printf(" ]\n");
    }
}

int main() 
{
    struct Node* stack = NULL;
    int ch;
    char op;

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]): ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Push an element\n2. Pop an element\n3. Display the stack\n4. Exit\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch (ch) 
            {
                case 1:
                    Push(&stack);
                    break;
                case 2:
                    Pop(&stack);
                    break;
                case 3:
                    Display(stack);
                    break;
                case 4:
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
