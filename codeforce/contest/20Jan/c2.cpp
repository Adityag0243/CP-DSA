#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--; // Convert to 0-based index
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        // Find the two vertices with the highest degrees
        vector<pair<int, int>> degree_pairs;
        for (int i = 0; i < n; i++) {
            degree_pairs.push_back({degree[i], i});
        }

        // Sort by degree in descending order
        sort(degree_pairs.rbegin(), degree_pairs.rend());

        // Get the two highest degree vertices
        int first_vertex = degree_pairs[0].second;
        int second_vertex = degree_pairs[1].second;

        // Check if they are adjacent
        bool are_connected = (find(adj[first_vertex].begin(), adj[first_vertex].end(), second_vertex) != adj[first_vertex].end());

        // Calculate the maximum number of components
        int result;
        if (are_connected) {
            result = degree[degree_pairs[0].second] + degree[degree_pairs[1].second] - 2; // They are adjacent
        } else {
            result = degree[degree_pairs[0].second] + degree[degree_pairs[1].second] - 1; // They are not adjacent
        }

        cout << result << endl;
    }

    return 0;
}