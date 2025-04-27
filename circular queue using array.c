#include <stdio.h>
#include <stdlib.h>

// creating global variables for Circular queue
int front = -1, rear = -1;

void Insert(int Msize, int Q[])
{
    // declaring variables
    int i;

    // checking overflow condition
    if (front == (rear + 1) % Msize)
    {
        printf("Queue OVERFLOW!\n");
    }
    else
    {
        // taking inputs
        printf("Enter the value: ");
        scanf("%d", &i);
        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % Msize;
        }
        // inserting value in Circular queue
        Q[rear] = i;
    }
}

void Delete(int Msize, int Q[])
{
    // checking underflow condition
    if (front == -1)
    {
        printf("Queue UNDERFLOW!\n");
    }
    else
    {
        // removing element from Circular queue
        printf("Deleted element: %d\n", Q[front]);
        
        if (front == rear)
        {
            front = rear = -1;
        }
        else
            front = (front + 1) % Msize;
    }
}

void Display(int Msize,int Q[])
{
    if (front == -1)
    {
        printf("Queue UNDERFLOW!\n");
        return;
    }

    printf("[ ");
    
    // Loop from front to rear in a circular manner
    for (int i = front; ;i = (i + 1) % Msize)
    {
        printf("%d, ", Q[i]);

        if (i == rear)  // Stop when reaching rear
            break;
    }
    
    printf("]\n");
}

int main()
{

    int Msize;
    // taking subscript value from user
    printf("Enter the size of Circular Queue: ");
    scanf("%d", &Msize);

    int Q[Msize], ch;
    char op;

    // infinite loop
    while (1)
    {
        printf("\nDo you want to enter the menu? [Y/n]): ");
        scanf(" %c", &op);

        // checking condition for YES
        if (op == 'Y' || op == 'y')
        {
            printf("Menu:\n1. Insert an element to Circular Queue\n2. Delete an element from Circular Queue \n3. Display the Circular Queue\n4. Exit\nChoose an option: ");
            scanf("%d", &ch);

            // cases
            switch (ch)
            {
            case 1:
                Insert(Msize, Q);
                break;
            case 2:
                Delete(Msize, Q);
                break;
            case 3:
                Display(Msize,Q);
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
