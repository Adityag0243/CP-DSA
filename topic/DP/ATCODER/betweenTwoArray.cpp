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
#define MOD2            998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n;
vi a(3001), b(3001);
vvi dp(3002, vi(3002, 0));

signed main(){
    cin >> n;
    l(i,0,n) cin >> a[i];
    l(i,0,n) cin >> b[i];

    for(int i = 0; i<= 3000 ; i++){
        if( i >= a[0] && i <= b[0]) dp[0][i] = 1;
        else dp[0][i] = 0;
    }

    for(int val = 1; val <= 3000; val++) dp[0][val] += dp[0][val-1];

    for(int i = 1; i< n; i++ ){
        for(int val = a[i]; val <= b[i]; val++){
            dp[i][val] += dp[i-1][val];
            dp[i][val] %= MOD2;
        }
        for(int val = 1; val <= 3000; val++){
            dp[i][val] += dp[i][val-1];
            dp[i][val] %= MOD2;
        }
    }
    
    cout << dp[n-1][3000];
    return 0;
}