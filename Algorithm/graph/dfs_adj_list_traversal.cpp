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

    int no_of_connected_componenet=0;
    for (int i = 0; i < n; i++) {     // this will handle if graph is disconnected
        if (!visited[i]) {
            no_of_connected_componenet++;    // we can use this variable in visited array to identify whether visited or not and with that we can get array like 1 1 2 2 3 4 3 2 3 1    means all 1 are connected to each other 2 are another connected component connected with each other same with 3 and 4 as well 
            
            bfs(i); // Start BFS from any unvisited node
        }
    }


}