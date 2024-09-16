#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
 
int n,m;
vector<int> adj[100005];
int vis[100005]={0};
 
 
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
    
    l(i,0,n){
        if(vis[i]==0){

            vis[i]=1;
            queue<int> q;
            q.push(i);

            while(!q.empty()){
                int val  = q.front();
                q.pop();

                for(int neighbour : adj[val]){
                    
                    if(vis[neighbour] == vis[val]){
                        cout<<"IMPOSSIBLE";
                        return 0;
                    }
                    if(vis[neighbour] != 0) continue;// ye line yahi rhegi impossible block ke upar rakha to check hi nhi ho payega kae bar 
                    vis[neighbour]  =  3 - vis[val];
                    q.push(neighbour);
                }

            }
        }
    }

    l(i,0,n){
        cout<<vis[i]<<" ";
    }

}
