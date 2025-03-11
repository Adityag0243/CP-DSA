#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int MAXN = 100005;
const int LOG = 20;

vector<pair<int, int>> adj[MAXN]; 
int up[MAXN][LOG];   // storing 2^ith parent
int maxEdge[MAXN][LOG];
int depth[MAXN];

void dfs(int node, int parent, int weight) {
    up[node][0] = parent;
    maxEdge[node][0] = weight;
    for (int i = 1; i < LOG; i++) { 
        if (up[node][i - 1] != -1) {
            up[node][i] = up[up[node][i - 1]][i - 1];   // 2^i the parent assigning
            maxEdge[node][i] = max(maxEdge[node][i - 1] , maxEdge[up[node][i - 1]][i - 1]);   // so it will work if and only if tree is in order
        }
    }
    for (auto &p : adj[node]) {
        int neighbor = p.first, w = p.second;
        if (neighbor != parent) {
            depth[neighbor] = depth[node] + 1;
            dfs(neighbor, node, w);
        }
    }
}

int getMaxEdge(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int maxW = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]) {
            maxW = max(maxW, maxEdge[u][i]);
            u = up[u][i];
        }
    }
    if (u == v) return maxW;

    for (int i = LOG - 1; i >= 0; i--) {
        if (up[u][i] != up[v][i]) {
            maxW = max({maxW, maxEdge[u][i], maxEdge[v][i]});
            u = up[u][i];
            v = up[v][i];
        }
    }

    return max({maxW, maxEdge[u][0], maxEdge[v][0]});
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i < N; i++) {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].emplace_back(B, W);
        adj[B].emplace_back(A, W);
    }

    memset(up, -1, sizeof(up));
    depth[1] = 0;
    dfs(1, -1, 0);

    while (Q--) {
        int U, V;
        cin >> U >> V;
        cout << getMaxEdge(U, V) << '\n';
    }
}
