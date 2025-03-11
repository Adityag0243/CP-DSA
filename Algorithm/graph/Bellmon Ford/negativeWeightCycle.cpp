#include <bits/stdc++.h>
using namespace std;




// void bellmonFord(int source, vector<tuple<int,int,int>> &edges, vector<int> &dist){

//     // for source node dist is alredy zero  (there is a problem here it doesn't guarnatee to lead for checking negative cycle)....
//     // and we need n-1 more iteration after each iteration atleast one one node will be fixed and get its shortest path
//     // so n-1 iteration will be enough
//     for(int i= 1; i<dist.size(); i++){   // n-1 times  not edge.size()
//         for( auto &[u,v,w] : edges){
//             if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
//                 dist[v] = dist[u] + w;                
//             }
//         }
//     }
// }
bool bellmonFord(int source, vector<tuple<int,int,int>> &edges, int sumPositive){
    vector<int> dist(node_count, sumPositive + 1);
    dist[source] = 0; // take any node as source node it won't effect the result of checking negative cycle
 
    for(int i= 1; i<dist.size(); i++){   // n-1 times  not edge.size()
        for( auto &[u,v,w] : edges){
            if( dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;                
            }
        }
    }
    // if we iterate one more time and anyyyyyy one node is getting latest shortest path then it means there is negative cycle
    for (auto &[u, v, w] : edges) {
        if ( dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected!\n";
            return true;
        }
    }
    return false;
}

int main(){
    
    cout <<"Enter no of Node and no of Edge respectively: ";
    int node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<tuple<int, int, int>> edges;

    cout << "Enter m edge data: format(u,v,w) from u to v with weight w. That too 1 based input taking but implimenting zero based.\n";
    int sumPositive = 0;
    for(int i = 0; i<edge_count; i++){
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u - 1, v - 1, w);
        if(w > 0) sumPositive += w;
    }

    
    cout << "Enter Source Node: ";
    int source;
    while(true){
        cin >> source;
        if(source <= node_count && source > 0)break;
        cout << " Source must be > 0 && <= n. Please try again: ";
    }
    source--;  // making it zero based


    // vector<int> dist(node_count, INT_MAX);
    dist[source] = 0;
    // bellmonFord(source, edges, dist);
    cout << bellmonFord(source, edges, sumPositive);

    

}


