#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define vi vector<int>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define all(arr) arr.begin(), arr.end()
#define srt(arr) sort(arr.begin(), arr.end())
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    
    vi a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++) vp[i] = {b[i], a[i]};
    srt(vp);

    bitset<1e5+5> dp;
    dp[0] = 1;  

    l(i,0,n) {

        bitset<1e5 + 5> addOn = dp; 

        for (int j = 1; j <= vp[i].second; j++) {
            if(  (j *  vp[i].first) > 1e5 ) break;
            addOn |= (dp << (j *  vp[i].first));
        }

        dp = addOn;
    }

    while (q--) {
        int target;
        cin >> target;
        if(dp[target]) yes 
        else no
    }
}
