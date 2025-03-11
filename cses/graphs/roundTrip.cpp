#include <bits/stdc++.h>
using namespace std;


vector<int> parent(100005, -1);
vector<int> path;

bool fn(int source, vector<pair<int, int>> &edges, vector<int> &dist){
    cout <<" here " << endl;
    for (auto it : edges) {
        int u = it.first;
        int v = it.second;
        int w = -1;
        if(dist[u] + w < dist[v]){
            dist[v] = dist[u] + w;                
            parent[v] = u;
            parent[u] = v;
        }

    }
    cout <<" here " << endl;
    
    for (auto it : edges) {
        int u = it.first;
        int v = it.second;
        int w = -1;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            path.push_back(v);
            int temp = parent[v];
            for (int i = 0; i < dist.size() && temp != v && temp != -1 ; i++) {
                path.push_back(temp);
                temp = parent[temp];
            }
            return true;
        }
    }
    
    return false;
}

int main(){
    
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<pair<int, int>> edges;
    for(int i = 0; i<edge_count; i++){
        int u, v;
        cin >> u >> v;
        edges.push_back({u - 1, v - 1});
    }

    vector<int> dist(node_count, 0);
    dist[0] = 0;
    if( fn(0, edges, dist) ){
        cout << path.size() << endl;
        for( auto it : path){
            cout << it + 1 << " ";
        }
    }else{
        cout << "IMPOSSIBLE";
    }

    

}