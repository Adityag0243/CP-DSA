#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)

vector<int> adj[205];
bool vis[205];

int fn(int i) {
    vis[i] = true;
    int cnt = 1;
    for (int neighbour : adj[i]) {
        if (!vis[neighbour]) {
            cnt += fn(neighbour);
        }
    }
    return cnt;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n;
    cin >> n;
    vector<ll> x(n), y(n), r(n);

    l(i, 0, n) {
        cin >> x[i] >> y[i] >> r[i];
    }

    // Build directed adjacency list
    l(i, 0, n) {
        l(j, 0, n) {
            if (i != j) {
                ll distSq = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if (r[i] * r[i] >= distSq) {  // Can cow i communicate with cow j?
                    adj[i].push_back(j);
                }
            }
        }
    }

    int ans = 0;

    l(i, 0, n) {
        // Reset the visited array for each DFS run
        fill(vis, vis + n, false);
        ans = max(ans, fn(i));
    }

    cout << ans << endl;
    return 0;
}
