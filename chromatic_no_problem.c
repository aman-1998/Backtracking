#include<stdio.h>
#include<stdlib.h>
int x,flag=0;
void graph_coloring(int **G,int *color,int m,int n,int v);
int main()
{
    int n,i,j;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);
    int **G=(int**)malloc((n+1)*sizeof(int*));
    int *color=(int*)malloc((n+1)*sizeof(int));
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
                if(G[i][j]==1 || G[i][j]==0)
                    break;
                else
                    printf("\nInvalid input\n");
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
    graph_coloring(G,color,n,n,1);
    printf("\nChromatic no. = %d\n",x);
    return 0;
}
void graph_coloring(int **G,int *color,int m,int n,int v)
{
    int i,j;
    if(v==n+1)
    {
        for(i=1;i<=n;i++)
            color[i]=0;
        graph_coloring(G,color,m-1,n,1);
        if(flag==0)
        {
            x=m;// chromatic no.
            flag++;
        }
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
            return;
        }
    }
}
