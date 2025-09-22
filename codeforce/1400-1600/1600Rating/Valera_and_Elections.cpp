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
int n, u, v, t;
vi ans;


vi adj[200005];
vi repairCnt(200005, 0);
set<pair<int,int>> repair;


void dfs(int node, int par){
    if(node != 1 && adj[node].size() == 1) return;
    
    for(int child : adj[node]){
        if( child == par ) continue;
        dfs(child, node);
        if( repair.find({child,node}) != repair.end()  || repair.find({node,child}) != repair.end() ){
            repairCnt[child]++;
            repairCnt[node] = 2;
        }
        if(repairCnt[child] == 1){
            ans.pb(child);
        }
    }
    
}


signed main(){
    cin >> n;
    l(i,1,n){
        cin >> u >> v >> t;
        adj[u].pb(v);
        adj[v].pb(u);
        if( t == 2) repair.insert({u,v});
    }
    dfs(1,0);

    cout << ans.size() << endl;
    for(int leaf : ans) cout << leaf << " ";
    return 0;
}