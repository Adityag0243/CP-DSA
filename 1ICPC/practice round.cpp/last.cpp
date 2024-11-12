#include<bits/stdc++.h>
using namespace std;


int main(){
   int t;
   cin>>t;
   while(t--){
    int n;
    cin>>n;
    map<string,pair<int,int>> mp;
    while(n--){
        string s;
        cin>>s;
        int a;
        cin>>a;
        if(a) mp[s].first++;
        else mp[s].second++;
    }
    int ans = 0;
    for(auto it : mp){
        ans += max(it.second.first, it.second.second);
    }
    cout<<ans<<endl;
   }
}