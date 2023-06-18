#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j;
    cin>>n;
    for(i=1;i<=n-1;i++){
        cout<<" ";
    }
     for(i=1;i<=n;i++){
        cout<<"*";
    }
    cout<<"\n";
    for(i=2;i<=n-1;i++){
        for(j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(j=1;j<=n-1;j++){
            if(j==1 || j==n-1){
            cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<"\n";
    }
    for(i=1;i<=n;i++){
        cout<<"*";
        }
}
