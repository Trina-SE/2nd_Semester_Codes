#include<bits/stdc++.h>
using namespace std;
int main(){
    int r,c,i,j;
    cin>>r>>c;
    for(i=0;i<c;i++){
        cout<<'*';
    }
    cout<<"\n";
    for(i=0;i<r-2;i++){
        cout<<'*';
        for(j=0;j<c-2;j++){
            cout<<' ';
        }
        cout<<'*'<<"\n";
    }
    for(i=0;i<c;i++){
        cout<<'*';
    }

}
