#include<stdio.h>
int main()
{
    int a[10][10],n,i,j;
    int indeg,outdeg;
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
    printf("\nAdjacency Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    printf("\nVertex\tIndegree\tOutdegree\tTotaldegree\n");
    for(i=0;i<n;i++)
    {
        indeg=0;
        outdeg=0;
        for(j=0;j<n;j++)
        {
            outdeg=outdeg+a[i][j];
            indeg=indeg+a[j][i];
        }
        printf("%d\t%d\t\t%d\t\t%d\n",i+1,indeg,outdeg,indeg+outdeg);
    }
    return 0;
}
