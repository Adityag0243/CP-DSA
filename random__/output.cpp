#include <bits/stdc++.h>
using namespace std;

#define int int64_t

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input01.txt", "r", stdin);
    freopen("output01.txt", "w", stdout);
#endif

    int t; 
    cin >> t;
    while (t--) {
        int n; 
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << accumulate(v.begin(), v.end(), 0ll) << '\n';
    }
}
