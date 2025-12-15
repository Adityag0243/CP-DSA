#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 2e5;
    freopen("input04.txt", "w", stdout);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // cout << "No of test cases u wants : " ;
    int t; cin >> t;
    cout << t << "\n";

    for (int i = 0; i < t ; i++) {
        int n = rng() % cnt + 1;
        cout << n << "\n";
        cnt -= n;
        cnt = max(1, cnt);

        for (int j = 0; j < n; j++) {
            long long x = rng() % 1000000000 + 1;
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
