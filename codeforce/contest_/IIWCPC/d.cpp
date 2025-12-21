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
// #define x               first
// #define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n;
vi adj[100005];
vi depth(100005);

void dfs(int u, int p){
    for(int v : adj[u]){
        if( v == p) continue;
        depth[v] = depth[u]+1;
        dfs(v);
    }
}

signed main(){
    fastio;
    cin >> n;
    int u,v;
    l(i,1,n){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    depth[1] = 0;
    dfs(1, -1);
    double ans = 0;
    double one = 1;
    l(i,1,n+1){
        ans += one / (depth[i]+1);
    }

    cout << fixed <<setprecision(10) << ans;
    return 0;
}