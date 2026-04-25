#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* insert(struct node *root,int val)
{
    struct node *temp;
    if(root==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=val;
        temp->left=NULL;
        temp->right=NULL;
        return temp;
    }
    if(val<root->data)
        root->left=insert(root->left,val);
    else
        root->right=insert(root->right,val);
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int main()
{
    struct node *root=NULL;
    int ch,val;
    while(1)
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter value: ");
            scanf("%d",&val);
            root=insert(root,val);
        }
        else if(ch==2)
        {
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        }
        else if(ch==3)
        {
            printf("Preorder: ");
            preorder(root);
            printf("\n");
        }
        else if(ch==4)
        {
            printf("Postorder: ");
            postorder(root);
            printf("\n");
        }
        else if(ch==5)
        {
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
