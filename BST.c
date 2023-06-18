#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node*left;
struct node*right;
struct node*parent;
};
struct node * root=NULL;
//for creating newnode
struct node *newnode(int key){
    � � struct node * temp=(struct node*)malloc(sizeof(struct node));
    � � temp->data=key;
    � � temp->left=temp->right=temp->parent=NULL;
    � � return temp;
}
//Max value ber korsi
struct node * Extract_max(struct node* x)
{
    � � while(x->right!=NULL)
    {
        � � � � x=x->right;� �
    }
    � � return x;
};
//Min value ber korsi
struct node * Extract_min(struct node* x)
{
    � � while(x->left!=NULL)
    {
� � � � x=x->left;� �
    }
    � � return x;
};
//Insert korsi value bst te
struct node* Insert(struct node * root,int key)
{
    � � struct node *y=NULL;
    � � struct node * x=root;
    � � struct node * z=newnode(key);
    � � while(x!=NULL)
    {
        � � � � y=x;
        � � � � if(z->data<x->data)
        {
            � � � � � � x=x->left;� � � �
        }
        � � � � else x=x->right;
    }
    � � z->parent=y;
    � � if(y==NULL)
    {
        � � � � root=z;�
    }

    � � else if(z->data<y->data)
    {
        � � �  y->left=z;
        � �
    }

    � � else y->right=z;

    � � return root;


}

//inorder traversal kore sorted data pabo

void inorder(struct node* root)

{

    � � if (root != NULL)
    {

        � � � � inorder(root->left);

        � � � � printf("%d ", root->data);

        � � � � inorder(root->right);

        � �
    }

}

//Tree search korbo

struct node* Tree_search(struct node * x,int k)
{

    � � if (x==NULL || k==x->data)
    {

        � � � � return x;

        � �
    }

    � � if(k<x->data)
    {

        � � � � return Tree_search(x->left,k);

        � �
    }

    � � else return Tree_search(x->right,k);

};

//Successor ber korar jonno

struct node * Tree_successor(int val)
{

    � � struct node* x=Tree_search(root,val);

    � � if (x->right!=NULL)
    {

        � � � � return Extract_min(x->right);

        � �
    }

    � � struct node* y=x->parent;

    � � while(y!=NULL&&x==y->right)
    {

        � � � � x=y;

        � � � � y=y->parent;

        � �
    }

    � � return y;


}

void Tree_delete(int key)
{

    � � struct node* z=Tree_search(root,key);

    � � struct node* y;

    � � struct node* x;


    � � if (z->left==NULL||z->right==NULL)
    {

        � � � � y=z;

        � �
    }

    � � else y=Tree_successor(z->data);

    � � if(y->left!=NULL)
    {

        � � � � x=y->left;

        � �
    }

    � � else x=y->right;

    � � if(x!=NULL)
    {

        � � � � x->parent=y->parent;

        � �
    }

    � � if(y->parent==NULL)
    {

        � � � � root=x;

        � �
    }

    � � else if(y==y->parent->left)
    {

        � � � � y->parent->left=x;

        � �
    }

    � � else y->parent->right=x;

    � � if(y!=z)
    {

        � � � � z->data=y->data;

        � �
    }

    � � //return y;


};

int main()
{

    � � int n;

    � � printf("How many elements do you want to insert in bst?\n");

    � � scanf("%d",&n);


    � � //bst te insert korbo element

    � � int r;

    � � printf("Enter the root of the binary search tree\n");

    � � scanf("%d",&r);

    � � root=Insert(root,r);

    � � printf("Enter the other elements of binary search tree\n");

    � � for(int i=1; i<n; i++)
    {

        � � � � int x;

        � � � � scanf("%d",&x);

        � � � � Insert(root,x);

        � �
    }


    � � //bst thik� moto hoise kina dekhar jonno inorder traversal kore print korsi

    � � printf("Printing in inorder format we have : \n");

    � � inorder(root);

    � � printf("\n");


    � � //min value ber korlam
    � � struct node * max=Extract_max(root);
    � � printf("Maximum value is %d\n",max->data);
    � � //max value ber korlam
    � � struct node * min=Extract_min(root);
    � � printf("Minimum value is %d\n",min->data);
    � � //search thik moto kaj kortese naki dekhar jonno
    � � printf("Enter the element you want to search:\n");
    � � int a;
    � � scanf("%d",&a);
    � � struct node * search=Tree_search(root,a);
    � � if(search==NULL)
    {
        � � � � printf("Element not found\n");� �
    }
    � � else
        � � printf("searched element is %d\n",search->data);
    � � //jekono element er successor ber kortesi
    � � printf("kar successor ber korbo?\n");
    � � scanf("%d",&a);
    � � struct node * success=Tree_successor(a);
    � � printf("successor is %d\n",success->data);
    � � //jekono element delete
    � � printf("Enter the element you want to delete \n");
    � � scanf("%d",&a);
    � � Tree_delete(a);
    � � printf("After deletion:\n");
    � � inorder(root);
    � � printf("\n");
}
