#include <stdio.h>
#include <stdlib.h>

void Addition()
{
    //Declaring Variables
    int r1,r2,c1,c2,i,j;

    //Taking Inputs from User
    printf("Enter the dimensions of the Matrix A: \n");
    printf("Row : ");
    scanf("%d",&r1);
    printf("Column : ");
    scanf("%d",&c1);

    printf("Enter the dimensions of the Matrix B: \n");
    printf("Row : ");
    scanf("%d",&r2);
    printf("Column : ");
    scanf("%d",&c2);

    //Array declaration
    int m1[r1][c1],m2[r2][c2],am[c1][c2];

    //for checking the column equality
    if(c1 == c2)
    {
        //Matrix A
        printf("Enter the values for the matrix A : \n");
        for(i = 0;i < r1;i++)
        {
            for(j = 0;j < c1;j++ )
            {
                printf("Enter element A%d%d : ",i + 1, j+1);
                scanf("%d",&m1[i][j]);
            }
        }

        //Matrix B
        printf("Enter the values for the matrix B : \n");
        for(i = 0;i < r2;i++)
        {
            for(j = 0;j < c2;j++ )
            {
                printf("Enter element B%d%d : ",i + 1, j+1);
                scanf("%d",&m2[i][j]);
            }
        }
        
        //Sum of two Matrix
        for(i = 0;i < c1;i++)
        {
            for(j = 0;j < c2;j++ )
            {
                am[i][j] = m1[i][j] + m2[i][j];
            }
        }

        //Printing Sum
        printf("\nPrinting the Sum of both Matrices\n");
        for(i = 0;i < c1;i++)
        {
            printf("| ");
            for(j = 0;j < c2;j++ )
            {
                printf(" %d ",am[i][j]);
            }
            printf(" |\n");
        }
    }
    else
    {
        printf("Column dimensions aren't equal\nexiting...\n");
        
    }
      
}


void Multiplication()
{
    //Declaring Variables
    int r1,r2,c1,c2,i,j,k;

    //Taking Inputs from User
    printf("Enter the dimensions of the Matrix A: \n");
    printf("Row : ");
    scanf("%d",&r1);
    printf("Column : ");
    scanf("%d",&c1);

    printf("Enter the dimensions of the Matrix B: \n");
    printf("Row : ");
    scanf("%d",&r2);
    printf("Column : ");
    scanf("%d",&c2);

    //Array declaration
    int m1[r1][c1],m2[r2][c2],mm[r2][c1];

    //for checking both dimension equality
    if(r2 != c1)
    {
        printf("Dimension of both matrices aren't equal!\nExiting...\n");
        
    }
    else
    {
        //Matrix A
        printf("Enter the values for the matrix A : \n");
        for(i = 0;i < r1;i++)
        {
            for(j = 0;j < c1;j++ )
            {
                printf("Enter element A%d%d : ",i + 1, j+1);
                scanf("%d",&m1[i][j]);
            }
        }

        //Matrix B
        printf("Enter the values for the matrix B : \n");
        for(i = 0;i < r2;i++)
        {
            for(j = 0;j < c2;j++ )
            {
                printf("Enter element B%d%d : ",i + 1, j+1);
                scanf("%d",&m2[i][j]);
            }
        }

        for(i = 0;i < r2;i++)
        {
            for(j = 0;j < c1;j++ )
            {
                //initiallized the matrix as 0
                mm[i][j] = 0;
                
                //Multiplication of two Matrix and adding to another matrix
                for(k = 0;k < c2;k++ )
                {
                    mm[i][j] += m1[i][k] * m2[k][j];
                }
            }
        }

        //Printing Muliplication 
        printf("\nPrinting the Multiplication of both Matrices\n");
        for(i = 0;i < r2;i++)
        {
            printf("| ");
            for(j = 0;j < c1;j++ )
            {
                printf(" %d ",mm[i][j]);
            }
            printf(" |\n");
        }
    }    
}

int main()
{
    int ch;
    char option;

    while(1)
    {
        printf("Do you want to enter the Menu : [Y/n]\n");
        scanf(" %c",&option);

        //Checking condition
        if(option == 'Y' || option == 'y')
        {
            printf("Menu : \n1.Addition of Matrix\n2.Multiplication of Matrix\n3.Exit\nEnter Choice : ");
            scanf("%d",&ch);

            //Cases
            switch(ch)
            {
                case 1 :
                    Addition();
                    break;
                case 2 :
                    Multiplication();
                    break;
                case 3 :
                    exit(0);
                default : 
                    printf("Entered Wrong Choice");
                    break;
            }
        }
        else
        {
           printf("Exiting Program....");
           return 0;
        }
    }
    return 0;
}
