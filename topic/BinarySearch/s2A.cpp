#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;




int check(ll w,ll  h,ll mid,ll n){
    if(log10(mid/w)+log10(mid/h)>9){
        return 1;
    }
    if ((((mid/w)*(mid/h) )>= n)) return 1;
    return 0;
}

int main(){
    ll w,h,n;
    cin>>w>>h>>n;
    ll low=1;
    ll high=1e16;
    // ll high=max(w,h)*n;
    ll ans=1;
    // cout<<check(w,h,1e10,n)<<check(w,h,1e11,n)<<check(w,h,1e11,n)<<check(w,h,1e12,n)<<check(w,h,1e13,n);
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(w,h,mid,n)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }

    cout<<ans<<endl;
}