#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)

bool vis[100005]={false};
int coin[100005]={0};
vector<int> adj[100005];



int dfs(int i){
    vis[i]=true;
    int gold=coin[i];

    for(int friends : adj[i]){
        if( !vis[friends] ){
            gold = min(gold , dfs(friends) );
        }
    }
    return gold;

}


int main(){
    
    int n,m;
    cin>>n>>m;

    l(i,0,n) cin>>coin[i];

    l(i,0,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ll sum=0;

    l(i,0,n){
        if(!vis[i]){
            sum += dfs(i);
        }
    }
    cout<<sum<<endl;
        
    
}