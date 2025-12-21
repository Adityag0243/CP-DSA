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

int n,k;
vi a(101);
vvi dp(101, vi(100005, 0));

signed main(){
    cin >> n >> k;
    l(i,0,n) cin >> a[i];

    l(candy,0,a[0]+1) dp[0][candy] = 1;
    l(i,1,100005)  dp[0][i] += dp[0][i-1];

    for(int i = 1; i < n ; i++){
        for(int candy = 0; candy < 100005; candy++){
            dp[i][candy] += dp[i-1][candy];
            if(candy - a[i] > 0) dp[i][candy] -= dp[i-1][candy-a[i]-1];
            dp[i][candy] = (dp[i][candy] + MOD2) % MOD2;
        }
        for(int candy = 1; candy < 100005; candy++){
            dp[i][candy] += dp[i][candy-1];
            dp[i][candy] %= MOD2;
        }
    }

    if(k > 0) cout << (dp[n-1][k] - dp[n-1][k-1] + MOD2) % MOD2;
    else cout << 1;
    return 0;
}