#include <stdio.h>

//for linear searching
int linearSearch(int arr[], int size, int key) 
{
    int i;
    for(i = 0; i < size; i++) 
    {
        if (arr[i] == key)
        {
            return i; //returns the index
        }
    }
    return -1;
}

int main() 
{
    int Msize,i,key,result;
    char op;

    while (1) 
    {
        printf("\nDo you want to enter the values for the array? [Y/n]: ");
        scanf(" %c",&op); 

        //checking condition for YES
        if (op == 'Y' || op == 'y') 
        {
            printf("\nEnter the size of array: ");
            scanf("%d", &Msize);

            int arr[Msize];

            for (i = 0; i < Msize; i++) 
            {
                printf("Enter Array element %d: ", i+1);
                scanf("%d", &arr[i]);
            }
            
            printf("\nEnter the value to find its index position : ");
            scanf("%d",&key);

            result = linearSearch(arr, Msize, key);

            if (result != -1)
            {
                printf("Element %d found at index %d.\n", key, result);
            }
            else
            {
                printf("Element %d doesn't exist in array.\n", key);
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
