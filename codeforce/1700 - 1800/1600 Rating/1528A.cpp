#include<bits/stdc++.h>
using namespace std;

#define int int64_t
#define vi vector<int>
#define pb push_back
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int fn(int node, int par, vector<int> adj[], vector<vector<int>> &dp, vector<int> &l, vector<int> &r, int lr){
    // base case
    if( adj[node].size() == 1  && adj[node][0] == par) return 0;
    if( dp[node][lr] != -1 ) return dp[node][lr];

    // lr ==> 0 means left taken for curent node else right taken
    int mine = (lr == 0 ? l[node] : r[node]);

    // lr to l
    int c = 0;
    for(int child : adj[node]){
        if( child == par) continue;
        c += max(
                    abs(mine - l[child]) + fn(child, node, adj, dp, l, r, 0), 
                    abs(mine - r[child]) + fn(child, node, adj, dp, l, r, 1)
                ) ;
    }


    return dp[node][lr] = c;
}

signed main(){
    fastio
    int t; cin >> t; 
    while( t-- ){
        int n; cin >> n;
        vi l(n+1);
        vi r(n+1); 
        for(int i = 1; i<=n; i++) cin >> l[i] >> r[i];

        vector<int> adj[n+1];
        for(int i = 1; i <n ; i++){
            int u,v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<vector<int>> dp(n+1, vector<int>(2, -1));

        cout << max(fn(1, 0, adj, dp, l, r, 0) , fn(1, 0, adj, dp, l, r, 1)) << endl;
    }
}