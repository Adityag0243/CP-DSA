#include<bits/stdc++.h>
using namespace std;

class edge{
    public:
    int to,weight;
    edge(int to , int weight){
        this->to = to;
        this->weight = weight;
    }
};

const int maxn = 100;
int n,m;  // no of nodes and edge
vector<vector<edge*>> adj;
vector<bool> visited;


void bfs(int node){
    queue<int> q;
    q.push(node);
    visited[q.front()] = true;

    while(!q.empty()){
        cout<<q.front()+1<<" ";
        
        for(edge* next : adj[q.front()]){
            if(!visited[next->to]){
                q.push(next->to);
                visited[next->to] = true;
            }
        }
        q.pop();
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        visited.push_back(false);
        vector<edge*> v;
        adj.push_back(v);
    }

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        a--,b--;
        edge* e1=new edge(b,w);
        edge* e2=new edge(a,w);
        adj[a].push_back(e1);
        adj[b].push_back(e2);
    }

    for (int i = 0; i < n; i++) {     // this will handle if graph is disconnected
        if (!visited[i]) {
            bfs(i); // Start BFS from any unvisited node
        }
    }


}