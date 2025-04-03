// given n node and m edges (u,v) create graph with those edges by taking one by one 
// while creating graph if any edge contribute any cycle in the graph then don'tadd it and print skip
// if by adding that edge it is not creating any cycle then add it....


#include<bits/stdc++.h>
using namespace std;


int grandfather(int node, vector<int>& parent){
    while( parent[node] != node){
        node = parent[node];
    }
    return node;
}

void unite(int u, int v, vector<int>& parent){
    int grandfather_ = grandfather(u, parent);
    parent[u] = grandfather_;
    parent[v] = grandfather_;
}


int main(){

    int n,m;
    cin >> n >> m;

    vector<int> parent(n);
    for(int i = 0; i<n ; i++) parent[i] = i;

    while(m--){
        int u,v;
        cin >> u >> v;
        u--; v--;

        if(grandfather(u, parent)  == grandfather(v, parent)){
            cout << "Skip\n";
        }else{
            unite(u,v,parent);
            cout <<"Taken\n";
        }
        for(auto it : parent) cout << it <<" ";
        cout<<endl;

    }
}