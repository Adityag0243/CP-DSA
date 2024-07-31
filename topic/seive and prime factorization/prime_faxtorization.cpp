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
    int n;
    cin>>n;
    vector<int> v(n+1);
    l(i,0,n+1) v[i]=i;
    l(i,2,n+1){
        if(v[i]==i)
        for(int j=i*i;j<=n;j+=i){
            if(v[j]==j) v[j]=i;
        }
    }
    cout<<v[n];
    n/=v[n];
    while(n>1){
        cout<<"*"<<v[n];
        n/=v[n];
    }

    return 0;
}