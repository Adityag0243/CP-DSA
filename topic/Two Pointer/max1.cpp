/* 01110100111101011110    k=3 flip any zero to 1 (k such operation allowed)so that we can get maximum consecutive length of 1's */ 


#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter Binary Array or string ";
    string a;
    cin>>a;
    int k;
    cout<<"Enter k ";
    cin>>k;


    int ans=0;
    int op=0;  //operation
    for(int i=0;i<a.size();i++){
        op=0;
        for(int j=i;j<a.size();j++){
            if(a[j]=='0') op++;
            if(op<=k) ans=max(ans,j-i+1);
            else break;
        }
    }
    cout<<"max length of 1's is : "<<ans;
    
}