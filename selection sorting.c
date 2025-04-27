#include <stdio.h>
#include <stdlib.h>

//For selection sorting
void Sort(int arr[], int Msize) 
{
    int i,j;
    for (i = 0; i < Msize - 1; i++) 
    {
        int minIndex = i;

        // Find the index of the minimum element
        for (j = i + 1; j < Msize; j++) 
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap if minIndex has changed
        if (minIndex != i) 
        {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

//printing the array
void Display(int arr[], int Msize) 
{
    int i;
    printf("[ ");
    for (i = 0; i < Msize; i++)
    {
        printf("%d,", arr[i]);
    }
    printf(" ]\n");
}

int main() 
{
    int Msize,i,ch;
    char op;
    
    printf("Enter the size of array: ");
    scanf("%d", &Msize);
    int arr[Msize];
    for (i = 0; i < Msize; i++) 
    {
        printf("Enter Array element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    //infinite loop
    while (1) 
    {
        printf("\nDo you want to enter the menu? [Y/n]: ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("Menu:\n1. Sort the Array \n2. Display the Array\n3. Exit\nChoose an option: ");
            scanf("%d", &ch);
            
            //cases
            switch (ch) 
            {
                case 1:
                    Sort(arr,Msize);
                    printf("Array Sorted!");
                    break;
                case 2:
                    Display(arr,Msize);
                    break;
                case 3:
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
