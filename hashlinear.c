#include<stdio.h>
int a[10];
int n;

void insert(int key)
{
    int pos,i;
    pos=key%n;
    i=0;
    while(i<n)
    {
        if(a[pos]==-1)
        {
            a[pos]=key;
            printf("Inserted %d at position %d\n",key,pos);
            return;
        }
        pos=(pos+1)%n;
        i++;
    }
    printf("Hash table is full!\n");
}

void display()
{
    int i;
    printf("\nIndex\tValue\n");
    for(i=0;i<n;i++)
    {
        if(a[i]==-1)
            printf("%d\t-\n",i);
        else
            printf("%d\t%d\n",i,a[i]);
    }
}

void search(int key)
{
    int pos,i;
    pos=key%n;
    i=0;
    while(i<n)
    {
        if(a[pos]==key)
        {
            printf("Key %d found at position %d\n",key,pos);
            return;
        }
        if(a[pos]==-1)
            break;
        pos=(pos+1)%n;
        i++;
    }
    printf("Key %d not found!\n",key);
}

int main()
{
    int i,ch,key;
    printf("Enter table size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        a[i]=-1;
    while(1)
    {
        printf("\n1.Insert\n2.Search\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter key: ");
            scanf("%d",&key);
            insert(key);
        }
        else if(ch==2)
        {
            printf("Enter key to search: ");
            scanf("%d",&key);
            search(key);
        }
        else if(ch==3)
        {
            display();
        }
        else if(ch==4)
        {
            break;
        }
    }
    return 0;
}
