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


int dfs(int node, vector<bool> &vis, vi adj[], int min_d){
    vis[node] = true;
    min_d = min(min_d, (int)adj[node].size());
    for( auto child : adj[node]){
        if(!vis[child]){
            dfs(child, vis, adj, min_d);
        }
    }
    return min_d;
}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,v; cin >> n;
        vi adj[n+1];
        set<pair<int,int>> st;

        l(i,1,n+1){
            cin >> v;
            if(st.find({v,i}) != st.end()  ) continue;
            st.insert({i,v});
            adj[i].pb(v);
            adj[v].pb(i);
        }

        vector<bool> vis(n+1, false);
        int cnt_max = 0;
        int c1 = 0;
        l(i,1,n+1){
            if(!vis[i]){
                cnt_max++;
                if(dfs(i,vis,adj,2) == 1) c1++;
            }
        }
        // cout << c1 << " ";
        if(c1 > 1) c1--;
        cout << cnt_max - c1 << " " << cnt_max << endl;
    }
    return 0;
}