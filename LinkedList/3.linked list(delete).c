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
void delete(int position) {
    struct node *temp,*p;
    if(position==0) head=head->next;
    else {
        p=head;
        for(int i=0;i<position;i++)  {
            temp=p;
            p=p->next;
            if(p==NULL) exit(0);
        }
        temp->next=p->next;
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
    printf("\nafter delating:\n");
    delete(2);
    display_element();

}


