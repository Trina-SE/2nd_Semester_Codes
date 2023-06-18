#include<stdio.h>
#include<stdlib.h>

struct node{

   int data;
   struct node *left_child,*right_child;

};

struct node*create_node(){

    struct node*newnode;

    newnode=(struct node*)malloc(sizeof(struct node*));

         int x;

      scanf("%d",&x);
      printf("%d\n",x);

      if(x==-1) return 0;

      newnode->data=x;

      printf("Enter the left child of %d(-1 for no left child): ",x);

      newnode->left_child=create_node();

      printf("Enter the right child of %d(-1 for no right child): ",x);

      newnode->right_child=create_node();

      return newnode;



};

void display(struct node*root){

   if(root==0) return;

   display(root->left_child);

    printf("%d\t",root->data);

   display(root->right_child);
};

int main(){

    freopen("tree.txt","r",stdin);

    struct node *root;
     root=0;
    printf("Enter data(-1 for no node): ");
    root=create_node();
    printf("Inorder Traversal:\n");
    display(root);

}
