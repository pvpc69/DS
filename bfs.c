#include<stdio.h>
int a[10][10],visited[10],queue[10];
int front=-1,rear=-1,n;

void bfs(int start)
{
    int i,node;
    visited[start]=1;
    rear++;
    queue[rear]=start;
    if(front==-1)
        front=0;
    printf("%d ",start+1);
    while(front<=rear)
    {
        node=queue[front];
        front++;
        for(i=0;i<n;i++)
        {
            if(a[node][i]==1 && visited[i]==0)
            {
                visited[i]=1;
                rear++;
                queue[rear]=i;
                printf("%d ",i+1);
            }
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
    printf("BFS Traversal: ");
    bfs(start);
    printf("\n");
    return 0;
}
