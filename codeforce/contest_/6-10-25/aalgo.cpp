#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    int n,k; cin >> n >> k;
    vvi v(n, vi(3));
    l(i,0,n) l(j,0,3) cin >> v[i][j];

    int dp[1001][3][2][1501];
    // i row, j col, not used / used, k steps..
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = v[0][0];
    dp[0][1][0][0] = v[0][1];
    dp[0][2][0][0] = v[0][2];

    // for(int i = 1; i < n; i++){
    //     for( int j = 0; j < 3; j++){
    //         for( int used = 0; used <= 1; used++){
    //             for( int steps = 0; steps <= k ; steps++){
    //                 if( !used) {
    //                     if( j == 0) dp[i][j][0][steps] = max( {dp[i][j][0][steps], dp[i-1][2][0][steps], dp[i-1][2][1][steps]});
    //                     else  dp[i][j][0][steps] = max( {dp[i][j][0][steps], dp[i][j-1][0][steps], dp[i][j-1][1][steps]});
    //                 }else{
    //                     if( steps == 0) continue;

    //                     dp[i][j][1][steps] = max({ dp[i][j][1][steps], v[i-1][j] + v[i][j] + dp[i-1][j][0][steps-1]  });
    //                     if( j > 0){
    //                         dp[i][j][1][steps] = max({ dp[i][j][1][steps], v[i][j-1] + v[i][j] + dp[i][j-1][0][steps-1]  });
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    int ans = max(dp[n-1][2][0][k], dp[n-1][2][1][k]);

    cout << ans << endl;

    return 0;
}