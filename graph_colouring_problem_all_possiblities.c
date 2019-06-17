#include<stdio.h>
#include<stdlib.h>
void graph_coloring(int **G,int *color,int m,int n,int v);
void printSoln(int color[],int n);
int main()
{
    int m,n,i,j,v;
    printf("Enter no. of vertices of the graph: ");
    scanf("%d",&n);
    int *color=(int*)calloc((n+1),sizeof(int));
    int **G=(int**)malloc((n+1)*sizeof(int*));
    for(i=1;i<=n;i++)
        G[i]=(int*)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            while(1)
            {
                printf("Enter G[%d][%d] ",i,j);
                scanf("%d",&G[i][j]);
                if(G[i][j]!=0 && G[i][j]!=1)
                    continue;
                else
                    break;
            }

        }
    }
    printf("\nAdjacency Matrix:-\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",G[i][j]);
        printf("\n");
    }
    printf("Enter no. of colors: ");
    scanf("%d",&m);
    printf("Enter the vertex from which you want to start: ");
    scanf("%d",&v);
    graph_coloring(G,color,m,n,v);
    return 0;
}
void graph_coloring(int **G,int *color,int m,int n,int v)
{
    int i,j;
    if(v==n+1)
    {
        printSoln(color,n);
        return;
    }
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(G[v][j]==1)
            {
                if(color[j]==i)
                    break;
            }
        }
        if(j==n+1)
        {
            color[v]=i;
            graph_coloring(G,color,m,n,v+1);
            color[v]=0;
        }
    }
}
static int x=1;
void printSoln(int color[],int n)
{
    int i;
    printf("\nSolution %d:-\n",x++);
    for(i=1;i<=n;i++)
        printf("v%d is colored with %d\n",i,color[i]);
}
