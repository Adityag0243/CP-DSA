#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define int             long long
#define vi              vector<int>
#define endl            '\n'
#define pb              push_back
#define l(i,st,n)       for(int i=st;i<n;i++)


signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    l(i,0,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].pb({c,b});
    }

    vi dist(n+1, INT64_MAX);
    dist[0] = 0;

    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,0});

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int d = it.first;
        int i = it.second;

        if (d > dist[i]) continue; 
        
        for( auto ele : adj[i]){
            int d1 = ele.first;
            int j  = ele.second;
            if( d + d1 < dist[j] ){
                dist[j] = d + d1;
                pq.push({dist[j], j});
            }
        }

    }

    for(int i = 0 ; i<n ; i++) cout << dist[i] << " ";

    return 0;
}