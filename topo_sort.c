#include<stdio.h>
int a[10][10],indeg[10],visited[10],stack[10],top=-1,n;

void topo()
{
    int i,j,count,node;
    count=0;
    for(i=0;i<n;i++)
    {
        indeg[i]=0;
        visited[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            indeg[j]=indeg[j]+a[i][j];
        }
    }
    while(count<n)
    {
        for(i=0;i<n;i++)
        {
            if(indeg[i]==0 && visited[i]==0)
            {
                top++;
                stack[top]=i;
                visited[i]=1;
            }
        }
        if(top==-1)
        {
            printf("Cycle detected! Topological sort not possible.\n");
            return;
        }
        node=stack[top];
        top--;
        printf("%d ",node+1);
        count++;
        for(j=0;j<n;j++)
        {
            if(a[node][j]==1)
            {
                indeg[j]--;
            }
        }
    }
    printf("\n");
}

int main()
{
    int i,j;
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
    printf("Topological Order: ");
    topo();
    return 0;
}
