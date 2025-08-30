#include <bits/stdc++.h>
using namespace std;

#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int main() {
    fastio;

    int t; cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vector<int> dp[n+1];
        
        
        for(int i = 0; i<k ; i++){
            int l,r,m; cin >> l >> r >> m;
            dp[l-1].push_back(m);
            dp[r].push_back(-m);
        }

        multiset<int> ms;
        vector<int> ans(n);
        for(int i = 0; i<n; i++){
            for( int x : dp[i]){
                if( x > 0 ) ms.insert(x);
                else ms.erase(ms.find(-x));
            }
            int val = 1;
            while(true){
                if( ms.find(val) == ms.end() ) break;
                else val++;
            }
            ans[i] = val;
        }
        bool flag = true;
        for(int x : ans) if(x == n+1) flag = false;

        if(flag){
            for(int x : ans) cout << x << " ";
        }
        else cout << -1;

        cout << endl;
    }
    return 0;
}
