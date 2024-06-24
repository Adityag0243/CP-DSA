#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


bool check(ll s,int k,vector<ll> &v){
    int count=0;
    ll sum=0;
    l(i,0,v.size()){
        sum+=v[i];
        if(sum>s){
            sum=0;
            count++;
        }
    }
    return count<=k;
    
}


void binaryAns(int k,vector<ll> &v){
    ll low=1;
    ll high=1e15;
    ll ans=1;
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(mid,k,v)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }
    cout<<ans;
}



int main(){
    int n,k;
    cin>>n>>k;
    vector<ll> v(n);
    l(i,0,n){
        cin>>v[i];
    }
    binaryAns(k,v);

}