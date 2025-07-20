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


vector<bool> vis(200005, false);

bool bfs( int node, vvi & adj){
    
    queue<pair<int,int>> q;
    q.push({node,-1});
    vis[node] = true;
    bool flag = true;
    while( !q.empty() ){

        node = q.front().x;
        int par = q.front().y;
        q.pop();
        if(adj[node].size() > 2) flag = false;
        
        for( int neighbour : adj[node] ){

            if(adj[neighbour].size() > 2) flag = false;
            if (!vis[neighbour]) {
                vis[neighbour] = true;
                q.push({neighbour, node});
            }
            else if (neighbour != par && flag) {
                return true;
            }

        }
    }
    return false;
}


signed main(){

    // fastio
    int n, m; cin >> n >> m;
    vvi adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int cnt = 0;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (bfs(i, adj)) {
                cnt++;
            }
        }
    }

    cout << cnt ;

    return 0;
}