#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)

int max_val(int i,vector<int> &v){
    if(i==-1) return INT_MIN;
    return max(v[i],max_val(i-1,v));
}

int max_val2(int st,int end,vector<int> &v){
    if(st>end) return INT_MIN;
    if(st==end) return v[st];
    return max(max_val2(st,st+(end-st)/2,v),max_val2(st+(end-st)/2+1,end,v));
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    cout<<max_val(n-1,v)<<"  "<<max_val2(0,n-1,v);
}