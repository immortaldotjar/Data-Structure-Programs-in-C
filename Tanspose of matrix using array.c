#include <stdio.h>

void Transpose(int r,int c)
{
    //Array declaration
    int m[r][c],tm[r][c],i,j;

    //Checking dimension equality
    if (r == c)
    {
        //taking inputs from user
        printf("Enter the values for the matrix A : \n");
        for(i = 0;i < r;i++)
        {
            for(j = 0;j < c;j++ )
            {
                printf("Enter element A%d%d : ",i + 1, j+1);
                scanf("%d",&m[i][j]);
            }
        }
            
        //Transposing the elements of Matrix
        for(i = 0;i < r;i++)
        {
            for(j = 0;j < c;j++ )
            {
                tm[j][i] = m[i][j];
            }
        }

        //Printing Transposed matrix
        printf("\nPrinting the transpose of matrix\n");
        for(i = 0;i < r;i++)
        {
            printf("| ");
            for(j = 0;j < c;j++ )
            {
                printf(" %d ",tm[i][j]);
            }
            printf(" |\n");
        }
    }
    else
    {
        printf("Dimensions aren't equal\nExiting....");
    }

}

int main()
{
    //Declaring Variables
    int r,c;

    //Taking Inputs from User
    printf("Enter the dimensions of the Matrix A: \n");
    printf("Row : ");
    scanf("%d",&r);
    printf("Column : ");
    scanf("%d",&c);

    //calling function
    Transpose(r,c);
    
    return 0;
}
