#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("input.txt", "w", stdout);

    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

    // cout << "No of test cases u wants : " ;
    int t; cin >> t;
    cout << t << "\n";

    for (int i = 0; i < t; i++) {
        int n = rng() % 10 + 1;
        cout << n << "\n";

        for (int j = 0; j < n; j++) {
            long long x = rng() % 100 + 1;
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
