#include<stdio.h>
#include<stdlib.h>

const int max=6;
int graph[6][6];
char color[6];

void bfs(int source){

    int parent[6];
    int distance[6];

       for(int i=1;i<max;i++){
          color[i]='W';
          parent[i]=-1;
          distance[i]=INT_MAX;
       }
       int queue[max],start=0,end=0;
       queue[end]=source;
       end++;
       color[source]='G';
       distance[source]=0;
       parent[source]=-1;
         while(end-start>0){
            int v1=queue[start];
               for(int i=1;i<max;i++){
                  int v2=i;
                      if(graph[v1][v2]==1 && color[v2]=='W'){
                        color[v2]='G';
                        queue[end]=v2;
                        end++;
                        distance[v2]=distance[v1]+1;
                        parent[v2]=v1;
                      }
               }
               queue[v1]='B';
               start++;
         }

      for(int i=1;i<max;i++){
        printf("Distance from source %d to %d is: %d",source,i,distance[i]);
        printf("\nParent of %d is: %d\n",i,parent[i]);
      }



}

int main(){

    freopen("bfs.txt","r",stdin);

    int edge,v1,v2;
    printf("How many edges are in your graph?\n");
    scanf("%d",&edge);

    for(int i=0;i<edge;i++){
        scanf("%d%d",&v1,&v2);
        graph[v1][v2]=1;
    }
    printf("Enter the source?\n");
    int source;
    scanf("%d",&source);
  //  printf("%d",graph[5][1]);

     bfs(source);

}
