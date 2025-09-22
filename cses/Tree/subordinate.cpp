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

int n,v;
vi adj[200005];
vi sz(200005);

int dfs( int node, int par ){
    if( node != 1 && adj[node].size() == 1) return 0;
    for( int child : adj[node] ){
        if( child == par ) continue;
        sz[node] += 1 + dfs(child, node);
    }
    return sz[node];
}

signed main(){
    cin >> n;
    l(u,2,n+1){
        cin >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    l(i,1,n+1) cout << sz[i] << " "; 


    return 0;
}