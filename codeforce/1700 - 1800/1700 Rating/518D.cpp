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
    int n;
    double p;
    int t; 
    cin >> n >> p >> t;

    vector<vector<double>> dp(t+1, vector<double>(n+1, 0));
    dp[0][0] = 1;

    for(int i = 0; i < t;  i++){
        for(int j = 0; j <= n; j++){
            if (j == n) {
                dp[i + 1][j] += dp[i][j]; 
            } else {
                dp[i + 1][j + 1] += dp[i][j] * p;   
                dp[i + 1][j]     += dp[i][j] * (1 - p);
            }
        }
    }

    double ans = 0;
    for(int i =0; i <= n; i++){
        ans += i * dp[t][i];
    }

    cout << fixed << setprecision(10) << ans << endl;

    return 0;
}