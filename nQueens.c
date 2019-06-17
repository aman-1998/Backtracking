#include<stdio.h>
#include<stdlib.h>
int board[20][20];
void nQueens(int n,int row);
int isSafe(int n,int row,int col);
void printSoln(int n);
int main()
{
    int n;
    printf("Enter no. of queens: ");
    scanf("%d",&n);
    printf("\nSize of board = %d*%d\n",n,n);
    nQueens(n,0);
    return 0;
}
void nQueens(int n,int row)
{
    int col;
    if(row==n)
    {
        printSoln(n);
        return;
    }
    for(col=0;col<=n-1;col++)
    {
        if(isSafe(n,row,col)==1)
        {
            board[row][col]=1;
            nQueens(n,row+1);
            board[row][col]=0;
        }
    }
}
int isSafe(int n,int row,int col)
{
    int i,j;
    for(i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
            return 0;
    }
    i=row-1;
    j=col+1;
    while(i>=0 && j<=n-1)
    {
        if(board[i][j]==1)
            return 0;
        i--;
        j++;
    }
    i=row-1;
    j=col-1;
    while(i>=0 && j>=0)
    {
        if(board[i][j]==1)
            return 0;
        i--;
        j--;
    }
    return 1;
}
int x=1;
void printSoln(int n)
{
    int i,j;
    printf("\n\nSolution %d:-\n",x++);
    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=n-1;j++)
        {
            if(board[i][j]==1)
                printf("Q ");
            else
                printf("- ");
        }
        printf("\n");
    }
}
