#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)




int found(int target,int curr){
    int sum=0;
    while(target!=curr){
        if(target>curr){
            sum+=(target-curr);
            curr=target;
        }else{
            if(curr&1){
                sum+=1;
                curr+=1;
            }
            curr/=2;
            sum++;
        }
    }
    return sum;
}



int main(){
    int n,m;
    cin>>n>>m;
    cout<<found(n,m);
    
}