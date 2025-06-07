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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,k,z;
        cin >> n >> k >> z;
        vi v(n);
        l(i,0,n) cin >> v[i];

        vi dp(n);
        dp[0] = v[0];

        for(int i = 1; i<=k; i++){
            dp[i] = v[i] + dp[i-1];
        }
        // l(i,0,n) cout << dp[i] << " ";
        // cout << endl; 
        vi dp2(n);
        l(i,1,n){
            dp2[i] = v[i] + v[i-1];
        }
        l(i,1,n){
            if(dp2[i] < dp2[i-1]) dp2[i] = dp2[i-1];
        }

        // l(i,0,n) cout << dp2[i] << " ";
        // cout << endl;

        int ans = 0;

        for(int i = 0; i<= k; i++){
            int r = k - i;
            ans = max(ans, dp[i]);
            r = min(r,2*z);
            int extra = (r/2)*dp2[i];
            if(r % 2 == 1 && i > 0) extra += v[i-1];
            ans = max( ans, dp[i] + extra); 
            // cout << ans << " ";
        }
        

        cout << ans <<  endl;

    }
    return 0;
}
