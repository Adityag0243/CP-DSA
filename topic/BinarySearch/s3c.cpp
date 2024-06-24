#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


bool check(int d,int k,vector<int> &v){
    int count=1;
    int prev=0;
    l(i,1,v.size()){
        if(v[i]-v[prev]>=d){
            prev=i;
            count++;
        }  
    }
    return count>=k;   
}


void binaryAns(int k,vector<int> &v){
    int low=1;
    int high=2*1e9;
    int ans=1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,k,v)){
            ans=mid;
            low=mid+1;
        }else high=mid-1;
    }
    cout<<ans;
}



int main(){
    int n,k;
    cin>>n>>k;    
    vector<int> v(n);
    l(i,0,n){
        cin>>v[i];    
    }
    binaryAns(k,v);


    
    
    
    
    
    
}