//robber wants maximum loot but will not rob immediate home of those home which is already robbed
// for 100 1 100 1 ans is 200 for 100 100 1 1 ans is 101 for 100 1 1 100 ans is 200 yes read line one doeasn't say cant go to 4th after 1
//https://leetcode.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int

int robber(int j,vector<int> &v,vector<int> &dp){
    if(j>=v.size()) return 0;
    if(j==v.size()-1) dp[j]=v[j];
    if(dp[j]!=-1) return dp[j];
    dp[j]= max(v[j]+robber(j+2,v,dp),v[j+1]+robber(j+3,v,dp));
    return dp[j];
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> dp(n,-1);
    cout<<robber(0,v,dp);
}