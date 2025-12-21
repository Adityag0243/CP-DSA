#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> pos(n + 1), val(n + 1);
        iota(pos.begin(), pos.end(), 0); // pos[i] = i

        for (int i = 0; i < m; i++) {
            int x, y, v;
            cin >> x >> y >> v;

            val[pos[x]] += v;
            val[pos[y]] += v;
            swap(pos[x], pos[y]);
        }

        cout << *max_element(val.begin() + 1, val.end()) << '\n';
    }
}
