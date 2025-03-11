#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int to, weight;
    Edge(int to, int weight)
    {
        this->to = to;
        this->weight = weight;
    }
};




void djikstra(int source, vector<vector<Edge*>> &adj, vector<int> &dist){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    
    while( !pq.empty() ){
        int cur_dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();


        if (cur_dist > dist[node]) continue;

        for( Edge* it : adj[node] ){
            if( dist[it->to] > cur_dist + it->weight){
                dist[it->to] = cur_dist + it->weight;
                pq.push({dist[it->to], it->to});    
            }
        }
    }
}


void take_input(vector<int> &v, int n){
    while(true){
        cin >> v[0];
        if(v[0] > 0 && v[0] <= n ) break;
        cout << "Invalid input node must be > 0 and <= n. Please retry: ";
    }

    while(true){
        cin >> v[1];
        if(v[1] > 0 && v[1] <= n && v[1] != v[0] ) break;
        cout << "Invalid input node must be > 0 and <= n and can't be self loop. Please retry: ";
    }

    while(true){
        cin >> v[2];
        if(v[2] >= 0 ) break;
        cout << "Weight must be >= 0. Please try again : ";
    }
}

int main(){
    
    cout <<"Enter no of Node and no of Edge respectively: ";
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<vector<Edge*>> adj(node_count);

    cout << "Enter m edge data: format(u,v,w) from u to v with weight w. That too 1 based input taking but implimenting zero based.\n";
    for(int i = 0; i<edge_count; i++){
        cout << "Edge "<< i+1<<" : ";
        vector<int> v(3);
        take_input(v, node_count);  

        Edge* e1 = new Edge(v[1]-1,v[2]);
        adj[v[0]-1].push_back(e1);
    }

    
    cout << "Enter Source Node: ";
    int source;
    while(true){
        cin >> source;
        if(source <= node_count && source > 0)break;
        cout << " Source must be > 0 && <= n. Please try again: ";
    }
    source--;  // making it zero based


    vector<int> dist(node_count, INT_MAX);
    dist[source] = 0;
    djikstra(source, adj, dist);

    for(int i = 0; i<node_count ; i++) cout << dist[i] << " ";

}