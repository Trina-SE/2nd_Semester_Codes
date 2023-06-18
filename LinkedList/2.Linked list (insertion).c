#include<stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node*next;
};


  struct node*head=0;

void create_node(int x){
    struct node*newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=0;
        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
               while((temp->next)!=0){
                 temp=newnode;
            }
        }


    }


void display_element(){
     struct node*temp;
     temp=head;
     while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
     }
}
void insert_element(int position,int data){
    struct node *new,*p=head;
    int i;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=NULL;
    if(position==0) {
        new->next=head;
        head=new;
    }
    else {
        for(i=0;i<position-1;i++) {
            p=p->next;
            if(p==NULL) exit(0);
        }
        new->next=p->next;
        p->next=new;
    }





}
int main(){
    FILE*fp;
    fp=fopen("Linked list.txt","r");
    int x;
    while(!feof(fp)){
    fscanf(fp,"%d",&x);
    create_node(x);
    }
    fclose(fp);
    display_element();
    printf("\nAfter inserting element:\n");
    insert_element(0,9);
    display_element();

}


