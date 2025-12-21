// #include <bits/stdc++.h>
// using namespace std;
// #define l(i,st,n)       for(int i=st;i<n;i++)

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
    
//     int n, k;
//     cin >> n >> k;
    
//     vector<vector<long long>> v(n, vector<long long>(3));
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < 3; j++)
//             cin >> v[i][j];

//     // DP array: dp[i][j][used][steps]
//     // i -> row, j -> column (0,1,2), used -> 0/1, steps -> 0..k
//     vector<vector<vector<vector<long long>>>> dp(
//         n, vector<vector<vector<long long>>>(
//             3, vector<vector<long long>>(
//                 2, vector<long long>(k + 1, -1e9)
//             )
//         )
//     );


    
//     dp[0][1][1][1] = max(0ll, v[0][0] + v[0][1]);
//     dp[0][2][1][1] = max(dp[0][1][1][1], v[0][1] + v[0][2]);


//     for (int j = 0; j < 3; j++){
//         dp[0][j][0][0] = 0;
//     }

//     for(int i = 1; i < n; i++){
//         for( int j = 0; j < 3; j++){
//             // cout << "Column = " << j << " ::\n" ;
//             for( int used = 0; used <= 1; used++){
//                 // cout << "Used : " << used << " :::\n";
//                 for( int steps = 0; steps <= k ; steps++){
//                     if( !used) {
//                         if( j == 0) dp[i][j][0][steps] = max( {dp[i][j][0][steps], dp[i-1][2][0][steps], dp[i-1][2][1][steps]});
//                         else  dp[i][j][0][steps] = max( {dp[i][j][0][steps], dp[i][j-1][0][steps], dp[i][j-1][1][steps]});
//                     }else{
//                         if( steps == 0) continue;
//                         dp[i][j][1][steps] = max({ dp[i][j][1][steps],
//                                 v[i-1][j] + v[i][j] + dp[i-1][j][0][steps-1], 
//                                 dp[i-1][2][1][steps], 
//                                 dp[i-1][2][0][steps]  
//                             });
//                         // cout << dp[i][j][1][steps] << "  ......\n";
//                         if( j > 0){
//                             dp[i][j][1][steps] = max({ dp[i][j][1][steps], v[i][j-1] + v[i][j] + dp[i][j-1][0][steps-1], dp[i][j-1][1][steps]  });
//                         }

//                     }
                    
//                     // cout << dp[i][j][used][k] << " ";
//                 }
//                 // l(st, 0, k+1) cout << dp[i][j][used][st] << " ";
//                 // cout << endl;
//             }
//         }
//     }

//     long long ans = 0;
    

//     cout << max(dp[n-1][2][0][k], dp[n-1][2][1][k]) << "\n";

//     return 0;
// }
