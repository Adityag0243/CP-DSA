#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


vector<set<int>> adj_a(1000006);
vector<int> adj_m[100];

vector<int> dijkstra(int source, int n, const vector<vector<pair<int, int>>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    pq.push({0, source}); 
    while (!pq.empty()) {
        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();        
        if (u_dist > dist[u]) continue;   
        for (const pair<int, int>& neighbor : adj[u]) {
            int v = neighbor.first;     
            int weight = neighbor.second;         
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

signed main(){
    int n , m;
    cin >> n >> m;
    l(k,0,m){
        int a;
        cin >> a;
        l(i,0,a){
            int b;
            cin >> b;

            if(adj_a[b].size()){
                for( auto it = adj_a[b].begin() ; it != adj_a[b].end() ; it++){
                    adj_m[b] = adj_m[*it];
                    adj_m[*it] = adj_m[b];
                }
            }
            adj_a[b].insert(k);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int a , b;
        cin >> a >> b;
        
        
    }
    

    
}