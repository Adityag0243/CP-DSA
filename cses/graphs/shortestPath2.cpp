#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<vector< long long >> dp(n, vector<long long>(n, LLONG_MAX));

    for(int i= 0 ; i< n ; i++) dp[i][i] = 0;

    for(int i = 0; i<m ; i++){
        int a, b , c;
        cin >> a >> b >> c;

        a--; b--;
        dp[a][b] = min(dp[a][b], 1ll*c);
        dp[b][a] = min(dp[b][a], 1ll*c);
    }
    for(int k = 0; k < n ; k++){
        for(int i = 0;i <n ;i++) for(int j =0; j <n ; j++){
            if(dp[i][k] != LLONG_MAX  && dp[k][j] != LLONG_MAX){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        a--; b--;

        if(dp[a][b] == LLONG_MAX) cout << -1 << endl;
        else cout << dp[a][b] <<  endl;
    }
}