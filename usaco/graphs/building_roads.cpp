#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
 
int n,m;
vector<int> adj[100005];
int vis[100005]={0};
 
void dfs(int i , int cnt){
    vis[i]=cnt;
    
    for(int neighbour : adj[i]){
        if( vis[neighbour] == 0 ){
            vis[neighbour]=cnt;
            dfs( neighbour , cnt );
        }
    }
}
 
 
int main(){
    cin>>n>>m;
 
    l(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=0;
    vector<int> ans;
    
    l(i,0,n){
        if(vis[i]==0){
            ans.push_back(i+1);
            cnt++;
            dfs(i,cnt);
        }
    }
 
 
    cout<<cnt-1<<endl;
    l(i,0,ans.size()-1){
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
 
 
    
}
