#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *table[10];
int n;

void insert(int key)
{
    int pos;
    struct node *temp,*p;
    pos=key%n;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=key;
    temp->next=NULL;
    if(table[pos]==NULL)
    {
        table[pos]=temp;
    }
    else
    {
        p=table[pos];
        while(p->next!=NULL)
            p=p->next;
        p->next=temp;
    }
    printf("Inserted %d at index %d\n",key,pos);
}

void display()
{
    int i;
    struct node *p;
    printf("\nIndex\tValues\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",i);
        p=table[i];
        while(p!=NULL)
        {
            printf("%d -> ",p->data);
            p=p->next;
        }
        printf("NULL\n");
    }
}

void search(int key)
{
    int pos;
    struct node *p;
    pos=key%n;
    p=table[pos];
    while(p!=NULL)
    {
        if(p->data==key)
        {
            printf("Key %d found at index %d\n",key,pos);
            return;
        }
        p=p->next;
    }
    printf("Key %d not found!\n",key);
}

int main()
{
    int i,ch,key;
    printf("Enter table size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        table[i]=NULL;
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
