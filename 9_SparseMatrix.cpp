#include <stdio.h>
int main()
{
    int r,c,arr[10][10],size=0;
    printf("Enter no. of rows and columns of full matrix : ");
    scanf("%d %d",&r,&c);
    printf("Enter your full:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            scanf("%d",&arr[i][j]);
            if (arr[i][j]!=0)
            {
                size++;
            }
        }
    }
    // now size of new matrix will be (size,3)
    int mat[size][3],k=0;
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            if (arr[i][j]!=0)
            {
                mat[k][0]=i+1;
                mat[k][1]=j+1;
                mat[k][2]=arr[i][j];
                k++;
            }
        }
    }
    // printing the new matrix
    printf("Resultant sparse matrix:(row col data)\n");
    for (int i=0;i<size;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}