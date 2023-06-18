#include<stdio.h>
#include<stdlib.h>

struct node{
   char ch;
   int freq;
   struct node*left,*right;
};

struct bst_node{
   int size;
   int capacity;
   struct node**array;
};

struct node*newnode(char ch,int freq){

   struct node*temp=(struct node*)malloc(sizeof(struct node));
   temp->left=temp->right=NULL;
   temp->ch=ch;
   temp->freq=freq;

   return temp;
};

struct bst_node*createBST(int capacity){

  struct bst_node*bst=(struct bst_node*)malloc(sizeof(struct bst_node));
  bst->capacity=capacity;
  bst->size=0;
  bst->array=(struct node**)malloc(bst->capacity*sizeof(struct node*));

  return bst;

};

void swapping(struct node**a,struct node**b){

  struct node*t;
  t=*a;
  *a=*b;
  *b=t;

}

/*struct bst_node*create_bst(char character[],int frequency[],int size){

  struct bst_node*newNode=createBST(size);

   for(int i=0;i<size;i++){
    newNode->array[i]=newnode(character[i],frequency[i]);
 }
  newNode->size=size;
  return newNode;

};*/

void insert(struct node*root,struct bst_node*bst){

struct node *y=NULL;
struct node *x=root;
struct node * z=newnode(bst);

        while(x!=NULL){
                y=x;
                if(z->data<x->data)  x=x->left;
                else x=x->right;
                    }

        z->parent=y;
        if(y==NULL) root=z;
        else if(z->data<y->data) y->left=z;
        else y->right=z;
        createBST->array[siz]=root;
  }

struct node*createNewTree(char character[],int frequency,int size){

    struct node*left=NULL,*right=NULL,*up=NULL;
}

int leaf(struct node*root){

 return root->left&&root->right;

}

void print_bit(int a[],int n){

    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf("\n");
    }

}

void printing(struct node*root,int a[],int top){

   if(root->left){
    a[top]=0;
    printing(root->left,a,top+1);
   }
   if(root->right){
    a[top]=1;
    printing(root->right,a,top+1);
   }
   if(!leaf(root)){
    printf("%c:",root->c);
    print_bit(a,top);
   }
}

void huffman(char character[],int frequency[],int n){


    struct node*root=createNewTree(character,frequency,n);

    int a[50];

    printing(root,a,0);


}

int main(){
    int n=5;
    char character[]={'A','B','C','D'};
    int frequency[]={5,6,1,4};
    huffman(character,frequency,n);
}

