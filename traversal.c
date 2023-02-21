#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node
{
 struct node *right,*left,*prev;
 char data;
}*cur,*par,*root=NULL;

void preorder(struct node *);
void postorder(struct node *);
void inorder(struct node *);

int main()
{
  char a[100];
  int len,i,c;
  struct node *new_node;

  printf("Enter the Postfix Expression : ");
  gets(a);
  len=strlen(a);
  for(i=len-1 ; i>=0 ; i--)
  {
   new_node=(struct node *)malloc(sizeof(struct node));
   new_node->data=a[i];
   new_node->left=new_node->right=new_node->prev=NULL;
   if(root==NULL)
   {
     root=new_node;
     cur=par=root;
   }
   else
   {
    if(a[i]=='+' ||a[i]=='-' ||a[i]=='*'||a[i]=='/'||a[i]=='^')
    {
     if(par->right==NULL)
     {
      cur=new_node;
      par->right=cur;
      cur->prev=par;
      par=cur;
     }
     else if(par->left==NULL)
     {
      cur=new_node;
      par->left=cur;
      cur->prev=par;
      par=cur;
     }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
     par=cur;
    }
   }
   else
   {
    if(par->right==NULL)
    {
     cur=new_node;
     par->right=cur;
     cur->prev=par;
    }
    else if(par->left==NULL)
    {
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
    else
    {
     while(par->left!=NULL)
     {
      par=par->prev;
     }
     cur=new_node;
     par->left=cur;
     cur->prev=par;
    }
   }
  }
 }
 while(1)
 {
   printf("\n\nenter the choice :\n1. Inorde \n2. Preorder \n3. Postorder \n4. Exit\n\n");
   scanf("%d",&c);
   if(c==4)
   {
     printf("\nexit....!!!");
     break;
   }
switch(c)
{
 case 1:
 printf("\nInorder Traversal : ");
 inorder(root);
 break;

 case 2:
 printf("\nPreorder Traversal : ");
 preorder(root);
 break;

 case 3:
 printf("\nPostorder Traversal : ");
 postorder(root);
 break;

 case 4:
 break;

 default:
 printf("\nWrong choice....");
 break;
}
}
}

void inorder(struct node *root)
{
 if(root!=NULL)
 {
  inorder(root->left);
  printf("%c ",root->data);
  inorder(root->right);
 }
}
void preorder(struct node *root)
{
 if(root!=NULL)
 {
  printf("%c ",root->data);
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
  printf("%c ",root->data);
 }
}
