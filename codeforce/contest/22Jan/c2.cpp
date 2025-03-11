// #include <bits/stdc++.h>
// using namespace std;
// #define all(arr)        arr.begin(), arr.end()
// #define vi              vector<int>
// #define vvi             vector<vi>
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// #define p(x)            cout << (x) << endl;
// #define sp(x)           cout << (x) << " ";
// #define endl            '\n'
// #define pb              push_back
// #define mxv(arr)        *max_element(arr.begin(), arr.end())
// #define mnv(arr)        *min_element(arr.begin(), arr.end())
// #define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
// #define srt(arr)        sort(arr.begin(), arr.end())
// #define rev(arr)        reverse(all(arr))
// #define MOD2            1000000007
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// void dfs(int node, const vector<set<int>>& graph, vector<bool>& visited) {
//     visited[node] = true;
//     for (int neighbor : graph[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor, graph, visited);
//         }
//     }
// }

// int fn(vector<set<int>>& adj) {
//     int n = adj.size();
//     vector<bool> visited(n, false);
//     int conCpt = 0;

//     for (int i = 0; i < n; ++i) {
//         if (!visited[i]) {
//             ++conCpt;
//             dfs(i, adj, visited);
//         }
//     }

//     return conCpt;
// }

// signed main() {
//     fastio;

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;

//         vi f(n, 0), s(n, 0);
//         vector<set<int>> adj(n); // Properly size adjacency list

//         // Read edges
//         l(i, 0, n - 1) {
//             int a, b;
//             cin >> a >> b;
//             a--;
//             b--;
//             f[a]++;
//             s[b]++;
//             adj[a].insert(b);
//         }
  
//         if (n <= 2) {
//             cout << 0 << endl;
//             continue;
//         }

//         vector<pair<int, int>> vp;
//         l(i, 0, n) {
//             vp.pb({f[i] + s[i], i});
//         }

//         for(auto it : vp){
//             cout << it.second <<" : "<<it.first<<endl;
//         }

//         srt(vp); // Sort by imbalance
//         int fs = vp[n - 1].second;
//         int sd = vp[n - 2].second;

//         cout << "fs and sd "<<fs<<" :  "<<sd<<endl;

//         // Remove edges from fs and sd
//         vector<int> toErase(all(adj[fs]));
//         for (int it : toErase) {
//             adj[fs].erase(it);
//         }

//         toErase = vector<int>(all(adj[sd]));
//         for (int it : toErase) {
//             adj[sd].erase(it);
//         }

//         // Remove edges pointing to fs and sd
//         l(i, 0, n) {
//             if (i == fs || i == sd) continue;
//             adj[i].erase(fs);
//             adj[i].erase(sd);
//         }

//         int ans = fn(adj); // Count connected components
//         cout << ans << endl;
//     }
// }
