#include<stdio.h>
int a[10][10],visited[10],n;

void dfs(int node)
{
    int i;
    visited[node]=1;
    printf("%d ",node+1);
    for(i=0;i<n;i++)
    {
        if(a[node][i]==1 && visited[i]==0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int i,j,start;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
        visited[i]=0;
    printf("Enter starting vertex (1 to %d): ",n);
    scanf("%d",&start);
    start=start-1;
    printf("DFS Traversal: ");
    dfs(start);
    printf("\n");
    return 0;
}
