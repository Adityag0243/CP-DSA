#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)

int sum_odd(int i,vector<int> &v){
    if(i==-1) return 0;
    if(v[i]&1) return v[i]+sum_odd(i-1,v);
    return sum_odd(i-1,v);
}


int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    cout<<sum_odd(n-1,v);
}