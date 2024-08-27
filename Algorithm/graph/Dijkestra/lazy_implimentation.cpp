#include<bits/stdc++.h>
using namespace std;


// node start from 0 to n-1

class edge{
    public:
    int to,weight;
    edge(int to , int weight){
        this->to = to;
        this->weight = weight;
    }
};


int n,m;  // no of nodes and edge
vector<vector<edge*>> adj;
vector<bool> is_visited;
vector<int> dist;


void dijkstra(int source){

    priority_queue<pair<int,int>> pq;
    pq.push( make_pair(source,0) );

    while(!pq.empty()){
        int index    = pq.top().first;
        int min_dist = pq.top().second;
        pq.pop();
        
        if( min_dist > dist[index] ) continue;

        for( edge* element : adj[index] ){

            int new_dist = min_dist + element->weight;

            if( new_dist < dist[element->to] ){
                dist[element->to] = new_dist;
                pq.push( make_pair(element->to,new_dist) );
            }

        }

    }
}




int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        vector<edge*> v;
        adj.push_back(v);
    }

    
    // graph data input
    cout<<"Enter Starting Node , Destination Node and Weight:\n";
    for(int i=0;i<m;i++){
        cout<<"Enter connection "<<i+1<<" is : ";
        int a,b,w;
        cin>>a>>b>>w;
        // a--,b--;   // if you input node 1 based index it will convert it 0 based index (her eour input will be zero based)
        edge* e1=new edge(b,w);
        adj[a].push_back(e1);
        // edge* e2=new edge(a,w);  // if undirected then these line will be applicable
        // adj[b].push_back(e2);
    }


    // source input
    int source;
    cout<<"Enter Source: ";
    cin>>source;

    is_visited.resize(n,false);
    dist.resize(n,INT_MAX); 
    dist[source]=0;


    dijkstra(source);  // fn call to update dist 
    cout<<"Distance of nodes from source node "<<source<<" : ";

    for(int i=0;i<n;i++) if(dist[i]==INT_MAX) cout<<"INF "; else cout<<dist[i]<<" ";

}