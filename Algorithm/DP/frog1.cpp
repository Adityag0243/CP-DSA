// https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)

map<int,int> dp;
int n;
int min_cost(int i,vector<int> &v){
    if(i>=n-1) return 0;
    if(i==n-2){
        dp[i]=abs(v[v.size()-2]-v[v.size()-1]);
        return dp[i];
    }
    if(dp.find(i)!=dp.end()) return dp[i];
    dp[i]=min(abs(v[i]-v[i+1])+min_cost(i+1,v),abs(v[i]-v[i+2])+min_cost(i+2,v));
    return dp[i];
}


int main(){
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    dp[n-1]=0;
    cout<<min_cost(0,v);
}