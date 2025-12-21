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

int n,m;


int fn(int node, int level, int par,  vector<tuple<int,int,int>> adj[] ){
    if( adj[node].size() == 0 ) return 0;

    int c = 0;
    for( auto [ child, lvlc, cost]  : adj[node] ){
        // if( ( child == par && lvlc == level ) || lvlc < level) continue;
        
        if(lvlc > level || ( child != par  && lvlc == level) ) c = max(c, cost + fn(child, lvlc, node, adj));
    }

    return c;
}



signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m; 
        int u,v,w;

        vector<int> lvl[m+1]; // 0 means available hai..
        vector<tuple<int,int,int>> adj[n+1];
     

        int lv = 0;
        for(int i = 0; i < m ; i++){
            cin >> u >> v >> w;
            adj[u].pb({v, lv, w});
            adj[v].pb({u, lv, w});
            lvl[lv].pb(u);
            lvl[lv].pb(v);

            lv++;
        }
        int c = 0;
        for(int lv = 0; lv <= m ; lv++){
            for( int node : lvl[lv]){
                int val = fn(node, lv, -1, adj);
                // cout << val <<" for starting from node : " << node  << endl;
                c = max(c, val);
            }
        }

        cout << c << endl;
    }
    return 0;
}