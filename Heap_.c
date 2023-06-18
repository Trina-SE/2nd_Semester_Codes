#include<stdio.h>
#include<stdlib.h>

const int N=8;

//log(n)
void max_heapify (int Arr[ ], int i, int N)
    {    int largest;
        int left = 2*i;                //left child
        int right = 2*i +1;        //right child
        if(left<= N && Arr[left] > Arr[i])
              largest = left;
        else
             largest = i;
        if(right <= N && Arr[right] > Arr[largest] )
            largest = right;
        if(largest != i )
        {
            swap (Arr[i] , Arr[largest]);
            max_heapify (Arr, largest,N);
        }
     }

//O(n)
void build_maxheap (int Arr[ ],int n)
    {   int i;
        for(i = N/2 ; i >= 1 ; i--)
        {
            max_heapify (Arr,i) ;
        }
    }

//log(n)
 void min_heapify (int Arr[ ] , int i, int N)
    {
    int left  = 2*i;
    int right = 2*i+1;
    int smallest;
    if(left <= N && Arr[left] < Arr[ i ] )
         smallest = left;
    else
        smallest = i;
    if(right <= N && Arr[right] < Arr[smallest] )
        smallest = right;
    if(smallest != i)
    {
        swap (Arr[ i ], Arr[ smallest ]);
        min_heapify (Arr, smallest,N);
    }
    }

//O(n)
void build_minheap (int Arr[ ])
    {
        for( int i = N/2 ; i >= 1 ; i--)
        min_heapify (Arr, i,N);
    }

//Nlog(N)
void heap_sort(int Arr[ ])
    {
        int heap_size = N;
        build_maxheap(Arr);
        for(int i = N; i>=2 ; i-- )
        {
            swap(Arr[ 1 ], Arr[ i ]);
            heap_size = heap_size-1;
            max_heapify(Arr, 1, heap_size);
        }
    }

//O(n)
int maximum(int Arr[ ])
        {
            return Arr[ 1 ];  //as the maximum element is the root element in the max heap.
        }


//log(n)
int extract_maximum (int Arr[ ])
    {
        if(length == 0)
        {
    cout<< “Can’t remove element as queue is empty”;
            return -1;
        }
        int max = Arr[1];
        Arr[1] = Arr[length];
        length = length -1;
        max_heapify(Arr, 1);
        return max;
    }

//log(n)
void increase_value (int Arr[ ], int i, int val)
    {
        if(val < Arr[ i ])
        {
            cout<<”New value is less than current value, can’t be inserted” <<endl;
            return;
        }
        Arr[ i ] = val;
        while( i > 1 and Arr[ i/2 ] < Arr[ i ])
        {
            swap(Arr[ i/2 ], Arr[ i ]);
            i = i/2;
        }
    }

//log(n)
void insert_value (int Arr[ ], int val)
    {
        length = length + 1;
        Arr[ length ] = -1;  //assuming all the numbers greater than 0 are to be inserted in queue.
        increase_val (Arr, length, val);
    }

void print_array(int arr[],int size){

   for(int i=0;i<size;i++){
    printf("%d ",arr[i]);
   }

   printf("\n");

}

int main(){
   freopen("heap.txt","r",stdin);
   printf("Enter the size of the array: ");
   int n,i;
   scanf("%d",&n);
   printf("%d\n",n);
   int x[n+1];
   for(i=0;i<n;i++){
    scanf("%d",&x[i]);
   }
   printf("The array is:\n");
   print_array(x,n);

   build_maxheap(x);
   printf("The array representation of heap is:\n");
   print_array(x,n);


}

