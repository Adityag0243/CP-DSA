#include<bits/stdc++.h>
using namespace std;


int n,m;  // no of nodes and edge
vector<vector<int>> adj;



void dfs(int start, vector<bool>& visited) {
    cout << start+1 << " ";
    visited[start] = true;
    for (int i = 0; i < adj[start].size(); i++) {
        if (adj[start][i] != 0 && (!visited[i])) {
            dfs(i, visited);
        }
    }
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        vector<int> v(n,0);
        adj.push_back(v);
    }
    vector<bool> is_visited(n,false);
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        adj[a][b]=w;
        adj[b][a]=w;
    }
    dfs(0,is_visited);


}