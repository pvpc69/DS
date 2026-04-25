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

int height(struct node *root)
{
    int lh,rh;
    if(root==NULL)
        return 0;
    lh=height(root->left);
    rh=height(root->right);
    if(lh>rh)
        return lh+1;
    else
        return rh+1;
}

int isBalanced(struct node *root)
{
    int lh,rh,diff;
    if(root==NULL)
        return 1;
    lh=height(root->left);
    rh=height(root->right);
    diff=lh-rh;
    if(diff<0) diff=-diff;
    if(diff<=1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
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
    printf("Height of BST: %d\n",height(root));
    if(isBalanced(root))
        printf("Tree is Balanced.\n");
    else
        printf("Tree is Not Balanced.\n");
    return 0;
}
