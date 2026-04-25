#include<stdio.h>
int a[20],n;

void heapify(int n,int i)
{
    int largest,temp,left,right;
    largest=i;
    left=2*i+1;
    right=2*i+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i)
    {
        temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(n,largest);
    }
}

void heapsort()
{
    int i,temp;
    for(i=n/2-1;i>=0;i--)
    {
        heapify(n,i);
    }
    for(i=n-1;i>0;i--)
    {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(i,0);
    }
}

int main()
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    heapsort();
    printf("Sorted array: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
