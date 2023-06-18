#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,i,j,count=1;
    cin>>n;
    for(i=1;i<=n;i++){
            if(i%2!=0){
              count=1;
            }
            else{
                count=0;
            }
        for(j=1;j<=i;j++){
                if(count==1){
                    cout<<1<<" ";
                    count--;
                }
                else if(count==0){
                    cout<<0<<" ";
                    count++;
                }
            }
            cout<<"\n";
        }
    }



