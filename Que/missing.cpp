#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) v[i]=1+i;
    l(i,0,n-1){
        int a;
        cin>>a;
        v[a-1]=0;
    }
    l(i,0,n){
        if(v[i]!=0) cout<<v[i];
    }
    
}