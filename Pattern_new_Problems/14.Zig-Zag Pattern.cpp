#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=3;i++){//zig-zag er hight 3 porjonto hobe.
        for(j=1;j<=n;j++){
           if((i+j)%4==0){
            cout<<"*"<<" ";
           }
           else if(i==2 && j%4==0){
            cout<<"*"<<" ";
           }
           else{
            cout<<"  ";
           }
        }
        cout<<"\n";
    }
}
