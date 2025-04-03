// #include <bits/stdc++.h>
// using namespace std;
// #define int             int64_t
// #define MOD             998244353
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// signed main() {
//     fastio;
//     vector<int> p2(1002, 0);
//     p2[0] = 1;
//     for (int i = 1; i < 1002; i++) {
//         p2[i] = (p2[i - 1] * 2) % MOD;
//     }

//     vector<int> ans(1002, 0);
//     int cur = 0, x = 0, y = 0;
    
//     for (int i = 1; i <= 1001; i++) {
//         int temp1 = cur + p2[i - 1];
//         int temp2 = cur - p2[i - 1];

//         if (((i & 1) && (max(x, temp1) - min(y, temp1) <= max(x, temp2) - min(y, temp2))) ||
//             (!(i & 1) && (max(x, temp1) - min(y, temp1) >= max(x, temp2) - min(y, temp2)))) {
//             x = max(x, temp1);
//             y = min(y, temp1);
//             cur = temp1;
//         } else {
//             x = max(x, temp2);
//             y = min(y, temp2);
//             cur = temp2;
//         }

//         ans[i] = ((x - y) % MOD + MOD) % MOD;  // Ensures non-negative result
//     }

//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         cout << ans[n] << endl;
//     }
//     return 0;
// }
// // wrong...