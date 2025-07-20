#include<bits/stdc++.h>
using namespace std;


vector<int> getYourPath(int u, int v, vector<vector<int>>& next)
{
    if(next[u][v] == -1){
        return {};    // there is no path between u and v
    }

    vector<int> path = {u};
    while( u != v){
        u = next[u][v];
        if (u == -1) return {}; // safety check....
        path.push_back(u);
    }

    return path;

}





int main(){
    int n, m;
    cin >> n >> m;
    // vector<vector<int>> dp(n, vector<int>(n,INT_MAX));
    vector<vector<long long>> dp(n, vector<long long>(n, LLONG_MAX));
    vector<vector<int>> next(n, vector<int>(n, -1));


    for(int i= 0; i<n ; i++){
        dp[i][i] = 0;
    }
    for(int i = 0; i<m ; i++){
        int u,v,w;
        cin >> u >>v >>w;
        u--; v--; // if one based given..

        dp[u][v] = w;
        next[u][v] = v;    // for u to v taking v as intermediate edge(i.e going directly....)
        // dp[v][u] = w; // if undirected
    }


    for(int k = 0; k<n ; k++){
        for(int i =0; i<n; i++) for(int j = 0; j<n; j++){
            if (dp[i][k] != LLONG_MAX && dp[k][j] != LLONG_MAX) {
                if (dp[i][k] + dp[k][j] < dp[i][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    next[i][j] = next[i][k]; // for u to v we are first going to k... 
                        // as dp[i][k] != INF that means there must a path exist between them as wellllll
                }
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
            if (dp[i][j] == LLONG_MAX)
                cout << "INF ";
            else
                cout << dp[i][j] << " ";
        }
        cout << "\n";
    }




    // get path 
    cout <<"Input for u and v for which you want path : ";
    int u, v;
    cin >> u >> v;
    u--; v--;
    vector<int> path = getYourPath(u, v, next);
    if (path.empty()) {
        cout << "No path from " << u+1 << " to " << v+1 << "\n";
    } else {
        cout << "Shortest path: ";
        for (int node : path) cout << (node+1) << " "; // 1-based output
        cout << "\nDistance = " << dp[u][v] << "\n";
    }


}