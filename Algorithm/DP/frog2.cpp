// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)

vector<int> dp(1);
int n,k;

int min_cost(int i,vector<int> &v){

    if(i>=n-1) return 0;
    if(i==n-2){
        dp[i]=abs(v[v.size()-2]-v[v.size()-1]);
        return dp[i];
    }
    
    if(dp[i]!=INT_MAX) return dp[i];

    dp[i]=abs(v[i]-v[i+1])+min_cost(i+1,v);
    for(int j=2;(i+j)<n && j<=k;j++){
        if(dp[i+j]!=INT_MAX) dp[i]=min(dp[i],abs(v[i]-v[i+j])+dp[i+j]);
        else dp[i]=min(dp[i],abs(v[i]-v[i+j])+min_cost(i+j,v));
    }
    return dp[i];
}


int main(){
    cin>>n>>k;
    dp.resize(n);
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    // l(i,0,n) v[i]=i%100;
    l(i,0,n) dp[i]=INT_MAX;
    dp[n-1]=0;
    cout<<min_cost(0,v);
    
    
}