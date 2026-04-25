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

int countNodes(struct node *root)
{
    if(root==NULL)
        return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}

int countLeaf(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return countLeaf(root->left)+countLeaf(root->right);
}

int main()
{
    struct node *root=NULL;
    int n,i,val;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter values: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        root=insert(root,val);
    }
    printf("Total nodes: %d\n",countNodes(root));
    printf("Total leaf nodes: %d\n",countLeaf(root));
    return 0;
}
