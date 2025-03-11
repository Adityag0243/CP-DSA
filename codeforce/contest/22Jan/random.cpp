// #include <bits/stdc++.h>
// using namespace std;
// #define MOD 9998244353

// // PriyanshuSingh18

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n;
//         cin >> n;
//         vector<int> a(n);
//         for (int i = 0; i < n; i++) {
//             cin >> a[i];
//         }
        
//         array<int, 2> dp{};
//         dp[0] = 1; // Initial state
        
//         for (int i = 0; i < n; i++) {
//             array<int, 2> temp_dp{};
//             for (int x = 0; x < 2; x++) {
//                 int l;
//                 if (i == 0) {
//                     l = 0;
//                 } else if (x == 0) {
//                     l = a[i - 1] % MOD;
//                 } else if (i == 1) {
//                     l = 1;
//                 } else {
//                     l = (a[i - 2] + 1) % MOD;
//                 }

//                 for (int y = 0; y < 2; y++) {
//                     if (y == 0 && a[i] != l) {
//                         continue;
//                     }
//                     if (x == 1 && y == 1) {
//                         continue;
//                     }

//                     temp_dp[y] = (temp_dp[y]%mod + dp[x]%mod) % MOD;
//                 }
//             }
//             dp = temp_dp;
//         }

//         int ans = (dp[0] + dp[1]) % MOD;
//         cout << ans << "\n";
//     }
//     return 0;
// }
