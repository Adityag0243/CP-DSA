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

int n,p,c;
map<pair<int,int>, int> mp;  // for edge (u,v) --> edge_weight   filling in way u < v
vi adj[100005];
vi ncs(100005,1);


void dfs(int i, int p){
    int c = 0;
    for(int child : adj[i]){
        if( child != p ){
            dfs(child, i);
            c += ncs[child];
        }
    }
    ncs[i] += c;
}

signed main(){
    cin >> n;
    vi node_val(n+1); l(i,1,1+n) cin >> node_val[i];

    l(i,1,n){
        cin >> p >> c;
        adj[i+1].pb(p); 
        adj[p].pb(i+1); 
        mp[{i+1,p}] = c;
        mp[{p,i+1}] = c;
    }

    // now i have my tree

    // calculate node_cnt_in_subtree ncs
    vi vis(n+1, 0);
    dfs(1,0);

    // sad or not if sad add the ncs[cur_node] don't go to further subtree...
    l(i,1,n+1) vis[i] = 0; 
    queue< pair<int,int> > q;
    int ans = 0;
    q.push({1,0});
    
    while(!q.empty()){
        auto &[v, c] = q.front(); q.pop();
        vis[v] = 1;

        for( int u : adj[v]){
            if(vis[u] == 0){
                if( c + mp[{v,u}] > node_val[u]) ans += ncs[u];
                else{
                    //  no path lead to cost > node_value[child] if current cost is negative don't take it
                    q.push({u, max(0ll, c + mp[{v,u}]) } );  // greedy way --> if path cost is - take 0 cost
                }
            }
        }
    }
    cout << ans << endl;
}