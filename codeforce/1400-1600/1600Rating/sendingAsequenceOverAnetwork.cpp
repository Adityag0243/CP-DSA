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
        int n; cin >> n;
        vi v(n+1); l(i,1,n+1) cin >> v[i];

        // dp[i]   is it possible to make a array from the array prefix b (from 1 to i);
        vector<bool> dp(n+1, false);
        dp[0] = true;
        // if cur_num is going for right only after making sure someone else ended up exactly behind me
        // it is going left then it is making sure some has been ended up exactly before where I am able to reach in left
        l(i,1,1+n){
            if(dp[i-1] && i + v[i] <= n) dp[i+v[i]] = true;
            if( i - v[i] - 1 >= 0 && dp[i-v[i]-1]) dp[i] = true;
        }

        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}