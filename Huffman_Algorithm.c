#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
struct node
{
    char ch;
    int freq;
    Node *left,*right;
};

typedef struct minHeapNode HNode;
struct minHeapNode          // collection of address of every node
{
    int size;
    int capacity;
    Node **array;
};


// creating space for the collection
HNode *createMinHeap(int capacity)
{
    HNode *minHeap=(HNode *)malloc(sizeof(HNode));
    minHeap->capacity=capacity;
    minHeap->size=0;
    minHeap->array=(Node **)malloc(minHeap->capacity*sizeof(Node *));
    return minHeap;
}

// creating new node
Node *new_node(char ch,int freq)
{
    Node *temp=(Node *)malloc(sizeof(Node));
    temp->left=temp->right=NULL;
    temp->ch=ch;
    temp->freq=freq;

    return temp;
}

// swapping nodes
void swap(struct node **a,struct node **b)
{
    struct node *t;
    t=*a;
    *a=*b;
    *b=t;
}

//minheapify
void minHeapify(HNode *minheap,int p)
{
    int idx=p;
    int left=(2*p)+1;
    int right=(2*p)+2;

    if(left<minheap->size&&minheap->array[idx]->freq>minheap->array[left]->freq)
        idx=left;
    if(right<minheap->size&&minheap->array[idx]->freq>minheap->array[right]->freq)
        idx=right;
    if(idx!=p)
    {
        swap(&minheap->array[p],&minheap->array[idx]);
        minHeapify(minheap,idx);
    }
}

//calling funtion
void minHeapBuild(HNode *minHeap)
{
    int n=minHeap->size-1;
    for(int i=(n-1)/2; i>=0; i--)
    {
        minHeapify(minHeap,i);
    }
}

//creating min heap
HNode *createAndBuildMinHeap(char charArray[],int freq[],int size)
{
    HNode *minHeap=createMinHeap(size);
    for(int i=0; i<size; i++)
    {
        minHeap->array[i]=new_node(charArray[i],freq[i]);
    }
    minHeap->size=size;
    minHeapBuild(minHeap);
    return minHeap;
}

// check whether element left or not
int oneElement(HNode *minHeap)
{
    return minHeap->size==1;
}

// extracting min node
Node *extractMin(HNode *minHeap1)
{
    Node *temp=minHeap1->array[0];
    minHeap1->array[0]=minHeap1->array[minHeap1->size-1];
    --minHeap1->size;
    minHeapify(minHeap1,0);

    return temp;
}

// for inserting a node
void insert(Node *top,HNode *minHeap)
{
    ++minHeap->size;
    int siz=minHeap->size-1;
    while(siz>0&&minHeap->array[(siz-1)/2]->freq>top->freq)
    {
        minHeap->array[siz]=minHeap->array[(siz-1)/2];
        siz=(siz-1)/2;
    }
    minHeap->array[siz]=top;
}

//for creating huffman tree
Node *createHuffmanTree(char charArray[],int freq[],int size)
{
    struct node *left=NULL,*right=NULL,*top=NULL;
    HNode *minHeap=createAndBuildMinHeap(charArray,freq,size);
    while(!oneElement(minHeap))
    {
        left=extractMin(minHeap);
        right=extractMin(minHeap);
        top=new_node('$',left->freq+right->freq);
        top->left=left;
        top->right=right;
        insert(top,minHeap);
    }
    return extractMin(minHeap);
}

//check whether leaf or not
int isLeaf(Node *root)
{
    return root->left&&root->right;
}

//print code
void printArray(int arr[],int n)
{
    for(int i=0; i<n; i++)
        printf("%d",arr[i]);
    printf("\n");
}

//print character
void printCode(Node *root,int arr[],int top)
{
    if(root->left)
    {
        arr[top]=0;
        printCode(root->left,arr,top+1);
    }
    if(root->right)
    {
        arr[top]=1;
        printCode(root->right,arr,top+1);
    }
    if(!isLeaf(root))
    {
        printf("%c = ",root->ch);
        printArray(arr,top);
    }
}

//huffmanCodes function, the main activity starts from here
void HuffmanCodes(char charArray[],int freq[],int size)
{
    Node *root=createHuffmanTree(charArray,freq,size);

    int arr[50];
    printCode(root,arr,0);
}


int main()
{
    freopen("huffman.txt","r",stdin);
    char charArray[27];
    int freq[26];
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%c",&charArray[i]);
    }
    for(int i=0; i<n; i++)
    {
        scanf("%d",&freq[i]);
    }

    HuffmanCodes(charArray,freq,n);
}
