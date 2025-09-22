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
int n,k,u,v;
vi sz(200005, 0);
vi dep(200005, 0);
vi adj[200005];

int dfs( int node, int par){
    
    int c = 0;
    for( int child : adj[node]){
        if( child == par) continue;
        dep[child] = 1 + dep[node];
        c += dfs( child, node);
    }
    return sz[node] = 1 + c;
}

signed main(){
    cin >> n >> k;
    l(i,1,n){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dep[1] = 1;
    dfs(1,0);
    
    vi v;
    l(i,1,n+1){
        // if {node i --> tourism} (happiness provided by it == sz[i] -1)  
        //  else{node i as industry } (happiness provided == dep[i] - 1)
        v.pb(sz[i] - dep[i]);
    }
    srt(v);

    int ans = 0;
    rl(i,0,n-k){
        ans += v[n-1-i];
    }

    cout << ans;
    return 0;
}