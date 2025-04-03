#include <bits/stdc++.h>
using namespace std;


vector<int> parent;
vector<bool> is_visited;
int start = -1;

void fn(int node, vector<vector<int>>& adj, int par) {
    is_visited[node] = true;
    parent[node] = par;

    // cout <<"  node: "<<node<<"    ";
    for( auto neighbour : adj[node]){
        if( neighbour == par) continue;

        if(is_visited[neighbour] ){
            parent[neighbour] = node;
            start = neighbour;
            return;
        }
        fn(neighbour, adj, node);
        if(start != -1) return;
    }
    // cout <<" hm  ";
}


int main(){
    
    int node_count, edge_count;
    cin >> node_count >> edge_count;
    

    // vector<vector<int>> adj(node_count+1);
    parent.resize(node_count+1, -1);
    is_visited.resize(node_count+1, false);


    vector<vector<int>> adj(node_count);
    for(int i = 0; i<edge_count; i++){
        int u,v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    // cout << "ok... ";
    for (int i = 0; i < node_count; i++) {
        if (!is_visited[i] && start == -1) {
            fn(i, adj, -1);
            if(start != -1) break;
        }
    }
    // cout <<"  ok  ";

    vector<int> ans;
    // cout <<"kahaaa ";

    // for(int i= 0; i<node_count; i++)
        // cout << parent[i] <<" ";
    if(start != -1){
        // cout <<"start /... ";
        int end = start;
        ans.push_back(start);
        start = parent[start];
        while(start != end){
            // cout <<".. m . ";
            ans.push_back(start);
            start = parent[start];
        }
        ans.push_back(end);
        reverse(ans.begin(), ans.end());  
    }

    if(start != -1){
    
        cout << ans.size() << endl;
        for(auto it : ans) cout << it+1 << " ";
    }else{
        cout << "IMPOSSIBLE" << endl;
    }

}