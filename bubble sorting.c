#include <stdio.h>
#include <stdlib.h>

//for bubble sorting
void Sort(int arr[], int Msize) 
{
    int i,j;
    for (i = 0; i < Msize - 1; i++) 
    {
        for (j = 0; j < Msize - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                // Swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Printing the array
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