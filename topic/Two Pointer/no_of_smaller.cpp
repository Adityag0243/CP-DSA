#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++) 

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    l(i,0,n) cin>>a[i];
    l(i,0,m) cin>>b[i];
    
    int j=0; 
    l(i,0,m){   
        for(;j<n;j++){
            if(a[j]>=b[i]){
                cout<<j<<" ";
                break;
            }
        }
        if(j>=n) cout<<n<<" ";        
    }

}