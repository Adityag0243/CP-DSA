#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> x(n), r(n);
        for (int i = 0; i < n; i++) cin >> x[i];
        for (int i = 0; i < n; i++) cin >> r[i];
        
        map<int, int> mp; // x-coordinate -> max vertical length

        for (int i = 0; i < n; i++) {
            for (int d = 0; d <= r[i]; d++) {
                int len = 2 * (r[i] - d) + 1;
                mp[x[i] + d] = max(mp[x[i] + d], len);
                mp[x[i] - d] = max(mp[x[i] - d], len);
            }
        }

        int ans = 0;
        for (auto it: mp) ans += it.second;

        cout << ans << "\n";
    }
    return 0;
}
