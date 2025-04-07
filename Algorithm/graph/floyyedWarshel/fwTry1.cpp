#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));


    for(int i= 0; i<n ; i++){
        dp[i][i] = 0;
    }
    for(int i = 0; i<m ; i++){
        int u,v,w;
        cin >> u >>v >>w;
        u--; v--; // if one based given..

        dp[u][v] = w;
        // dp[v][u] = w; // if undirected
    }


    for(int k = 0; k<n ; k++){
        for(int i =0; i<n; i++) for(int j = 0; j<n; j++){
            if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // negative cycle detection...

    bool hasNegativeCycle = false;
    for (int i = 0; i < n; ++i) {
        if (dp[i][i] < 0) {
            cout << "Negative Cycle detected...\n";
            hasNegativeCycle = true;
        }
    }
    if (!hasNegativeCycle) {
        cout << "No negative cycle\n";
    }



    cout << "Shortest distances matrix:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }



}