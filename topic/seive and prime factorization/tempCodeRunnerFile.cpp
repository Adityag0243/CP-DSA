// https://atcoder.jp/contests/abc169/tasks/abc169_d

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


int main() {
    ll n;
    cin>>n;

    ll cnt=0;
    ll st=n;
    for(ll i=2;i<=n;i++){
        if(i*i>n){
            cnt++;
            break;
        } 
        if(n%i==0){
            cnt++;               
            n/=i;
            cout<<i<<":"<<n<<"  ";
        }
        
    }

    cout<<cnt;
    return 0;
}