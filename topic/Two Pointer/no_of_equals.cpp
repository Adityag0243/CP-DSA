#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
ll equals(vector<int> &a,vector<int> &b){
    ll total=0;
    l(i,0,b.size()){
        int l=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        int r=upper_bound(a.begin(),a.end(),b[i])-a.begin();
        cout<<r-l<<" ";
        total+=(r-l);
    }
    return total;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    l(i,0,n) cin>>a[i];
    l(i,0,m) cin>>b[i];

    cout<<equals(a,b);
}