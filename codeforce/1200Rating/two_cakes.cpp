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



int main(){
    int n,a,b;
    cin>>n>>a>>b;

    int ans=1;
    int lo=1;
    int hi=100;

    while(lo <= hi ){
        int mid= (lo+hi)/2;
        if( a/mid + b/mid >= n ){
            ans=mid;
            lo = mid+1;
        }else hi = mid-1;
    }

    cout<<min({ans,a,b})<<endl;
}