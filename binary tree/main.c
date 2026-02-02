#include <stdio.h>
#include <stdlib.h>

struct btree{
    int data;
    struct btree * left;
    struct btree * right;
};

struct btree * root, *  temp;
void create (){
temp = (struct btree *)malloc(sizeof(struct btree));
int n;
scanf("%d", &n);
temp -> data= n;
temp -> right = temp -> left = NULL;
}

void insert( struct btree * t)
{
    if(t-> data < temp->data && t -> right !=NULL)
    {
        insert(t->right);
    }
    else if (t -> data < temp -> data && t -> right == NULL){
        t-> right = temp;
    }
    else if ( t-> data > temp -> data && t-> left !=NULL){
        insert(t -> left);
    }
    else if( t -> data > temp -> data && t -> left == NULL)
    {
        t -> left =temp;
    }

}

void inorder (struct btree * t){
if(root == NULL){
    printf("no element ");
    return;
}
if(t-> left !=NULL)
{
    inorder( t-> left);

}
printf("%d", t->data);
if( t -> right != NULL)
{
    inorder (t-> right);
}
}

void preorder (struct btree *t){
if(root ==NULL)
{
    printf("No element");
    return;
}
printf("%d" , t -> data);
if(t-> left !=NULL)
    preorder(t-> left);
if( t-> right != NULL)
    preorder(t->right);

}
void postorder (struct  btree *t)
{
    if(root ==NULL)
    {
        printf("No element");
        return;
    }
    if( t-> left != NULL)
        postorder( t-> left);
    if(t-> right != NULL)
        postorder(t-> right);
       printf("%d", t->data);
}
int main()
{
    int n;
     scanf("%d", &n);
     root =0;
     for(int i=0; i<n; i++)
     {
         create ();
         if(root == NULL)
            root = temp;
         else
            insert(root);
     }

     inorder(root);
     printf("\n");
     preorder(root);
     printf("\n");
     postorder(root);
    return 0;
}
