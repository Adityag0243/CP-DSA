//cdf  
// https://codeforces.com/contest/1996/problem/D
// code from jiangly
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
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int ans=0;

        for(int a=1 ; a<=n && a<= x ; a++){
            for(int b=1 ; a*b <= n && a+b <= x ; b++){
                ans+= min( (n-a*b)/(a+b)  , x-a-b );
            }
        }
        cout<<ans<<endl;
    }
}