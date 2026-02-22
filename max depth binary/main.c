#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;
struct Node*left;
struct Node* right;
};

struct Node *createNode(int data){
   struct Node *node = (struct Node*)malloc(sizeof(struct Node));
   node ->data=data;
   node ->left=NULL;
   node ->right=NULL;
}
int maxdepth(struct Node* root){
if(root== NULL)
    return 0;
int leftdepth =maxdepth(root ->left);
int rightdepth = maxdepth(root ->right);
if(leftdepth > rightdepth)
    return leftdepth +1;
else
    return rightdepth +1;
}
int main()
{
   struct Node*root = createNode(1);
   root ->left = createNode(2);
   root ->right = createNode(3);

   root ->left ->left = createNode(4);
   root ->left ->right = createNode(5);

   root ->left ->right ->right = createNode(6);
   root ->left ->right ->right ->right = createNode(7);
   printf("Maximum depth is %d\n",maxdepth(root));
   return 0;
}
