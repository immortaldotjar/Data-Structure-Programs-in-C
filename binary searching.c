#include <stdio.h>

//for binary searching
int binarySearch(int arr[], int Msize, int key) 
{
    int low = 0, high = Msize - 1;

    while (low <= high) 
    {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1; // Not found
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
            
            printf("\nEnter the value to find its position : ");
            scanf("%d",&key);

            result = binarySearch(arr, Msize, key);

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