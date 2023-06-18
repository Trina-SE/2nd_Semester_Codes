#include<stdio.h>
void count_sort(int n,int a[],int m){
    int count[n],b[n];
    for(int i=0;i<n;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        printf("%d ",count[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",count[i]);
    }
    printf("\n");
    for(int i=1;i<n;i++){
        count[i]=count[i-1]+count[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",count[i]);
    }
    printf("\n");
    for(int i=n-1;i>=0;i--){
       count[a[i]]--;
       b[count[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",count[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }

}
int main(){
    int n;
    scanf("%d",&n);
    int a[n+1],m=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>m){
            m=a[i];
        }
    }
    count_sort(n,a,m);

}

/*10
2 1 2 3 4 2 10 8 1 5*/
