#include<stdio.h>
#include<stdlib.h>

struct node_include_char_freq {
    char c;
    int f;
    struct node_include_char_freq*left_child,*right_child;
};

struct bst_node{
     int data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
    struct node_include_char_freq**array;
};

struct node_include_char_freq*create_newnode(char ch,int fq){

struct node_include_char_freq*newnode=(struct node_include_char_freq*)malloc(sizeof(struct node_include_char_freq));

  newnode->left_child=newnode->right_child=NULL;
  newnode->c=ch;
  newnode->f=fq;

  return newnode;


};

struct bst_node*create_place(int key){

    struct bst_node * temp=(struct bst_node*)malloc(sizeof(struct bst_node));

    temp->data=key;

    temp->left=temp->right=temp->parent=NULL;

    temp->array=(struct create_newnode**)malloc(temp->data*sizeof(struct create_newnode*));

     return temp;
};

void swap(struct node_include_char_freq **a,struct node_include_char_freq**b){

   struct node_include_char_freq*t;
   t=*a;
   *a=*b;
   *b=t;

}

struct node_include_char_freq*createNewTree(char character[],int frequency,int size){

    struct node_include_char_freq*left_child=NULL,*right_child=NULL,*up=NULL;



}

int leaf(struct node_include_char_freq*root){

 return root->left_child && root->right_child;

}

void print_bit(int a[],int n){

    for(int i=0;i<n;i++){
        printf("%d",a[i]);
        printf("\n");
    }

}

void printing(struct node_include_char_freq*root,int a[],int top){

   if(root->left_child){
    a[top]=0;
    printing(root->left_child,a,top+1);
   }
   if(root->right_child){
    a[top]=1;
    printing(root->right_child,a,top+1);
   }
   if(!leaf(root)){
    printf("%c:",root->c);
    print_bit(a,top);
   }
}

void huffman(char character[],int frequency[],int n){


    struct node_include_char_freq*root=createNewTree(character,frequency,n);

    int a[50];

    printing(root,a,0);


}

int main(){

   freopen("huffman.txt","r",stdin);
   char character[27];
   int frequency[26];

   int n;
   scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        scanf("%c",&character[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&frequency[i]);
    }

    huffman(character,frequency,n);


}
