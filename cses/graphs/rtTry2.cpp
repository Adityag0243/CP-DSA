#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define endl            '\n'
#define pb              push_back

#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)

void fn(int i,vector<vector<int>> &adj,vector<bool>& is_visited,vector<int>& parent){

}



int main(){
    
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<vector<int>> adj(node_count);
    for(int i = 0; i<edge_count; i++){
        int u, v;
        cin >> u >> v;
        u--;v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    
    vector<bool> is_visited(node_count,false);
    vector<int> parent(node_count,-1);
    for(int i=0;i<node_count;i++){
        if(is_visited[i] == false) fn(i,adj,is_visited,parent);
    }
    

}