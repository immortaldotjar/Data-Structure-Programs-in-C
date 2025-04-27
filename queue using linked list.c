#include <stdio.h>
#include <stdlib.h>

//Creating new node
struct Node 
{
    int data;
    struct Node* next;
};

//Structure for queue with front and rear pointers
struct Queue {
    struct Node *front, *rear;
};

//Creating new queue
struct Queue* createQueue() 
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

//For inserting element in queue
void Insert(struct Queue* q) 
{
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) 
    {
        printf("Heap overflow!\n");
        return;
    }

    printf("Enter the value :");
    scanf("%d",&value);
    newNode->data = value;
    newNode->next = NULL;
    
    if (q->rear == NULL) 
    {
        q->front = q->rear = newNode;
    } 
    else 
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

//for deleting the element from queue
void Delete(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue UNDERFLOW!\n");
        return;
    }
    struct Node* temp = q->front;
    int deleteValue = temp->data;

    printf("Deleted element : %d\n",deleteValue);
    q->front = q->front->next;
    
    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    //for freeing up the memory
    free(temp);
}

// For displaying the elements of queue
void Display(struct Queue* q) 
{
    if (q->front == NULL) 
    {
        printf("Queue UNDERFLOW!\n");
        return;
    }
    struct Node* temp = q->front;
    
    printf("Queue elements: \n");
    printf("[ ");
    while (temp != NULL) 
    {
        printf("%d,", temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}

int main() 
{

    struct Queue* queue = createQueue();

    int ch;
    char op;

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]: ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Insert an element\n2. Delete an element\n3. Display the Queue\n4. Exit\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch(ch) 
            {
                case 1:
                    Insert(queue);
                    break;
                case 2:
                    Delete(queue);
                    break;
                case 3:
                    Display(queue);
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