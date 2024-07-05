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
int max_len(vector<ll> &a,ll s){
    if(a[a.size()-1]<s) return 0;
    int len=lower_bound(a.begin(),a.end(),s)-a.begin();
    cout<<len<<" ";
    int pt1=0;
    int pt2=len;
    while(pt2<a.size()){
        if(a[pt2]-a[pt1]>=s){
            len=min(len,pt2-pt1);
            pt1++;
        }else pt2++;
    }
    return len;
}

int main(){
    ll n,s;
    cin>>n>>s;
    vector<ll> a(n);
    l(i,0,n) cin>>a[i];
    l(i,1,n) a[i]+=a[i-1];

    cout<<max_len(a,s);


    //failed on
    // 7 15
    // 1 2 3 4 1 2 2
    
}