#include<stdio.h>
#define N 5

int stack[N];
int top=-1;

void push(){
    int x;
   printf("enter data:\n");
   scanf("%d",&x);
   if(top==N-1){
    printf("stack overflow!!\n");
   }
   else{
    top++;
    stack[top]=x;
   }
}

void pop(){

   int pop_item;

   if(top==-1){
    printf("stack underflow!!\n");
   }
   else{
    pop_item=stack[top];
    top--;
    printf("removed item is:%d\n",pop_item);
   }


}

void peek(){

   if(top==-1){
    printf("there is no iteam in stack!!\n");
   }
   else{
    printf("top item is:%d\n",stack[top]);
   }

}

void display(){

  int i;

  for(i=top;i>=0;i--){
    printf("%d\n",stack[i]);
  }

}

int main(){
    int c;
    do{
    printf("enter choice:\n0.exit\n1.push\n2.pop\n3.peek\n4.display\n");
    scanf("%d",&c);
    switch(c){
       case 1:push();
              break;
       case 2:pop();
              break;
       case 3:peek();
              break;
       case 4:display();
              break;
    default:printf("invalid choice\n");

    }

    }
    while(c!=0);
    return 0;
}
