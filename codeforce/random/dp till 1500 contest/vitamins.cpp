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
    int t = 1;
    // cin >> t;
    while(t--){
        int n; cin >> n;

        vector<vector<int>> dp(n+1, vector<int>(8, 5e6));
        
        l(i,0,n){
            int cst; cin >> cst;
            string s; cin >> s;
            int mask = 0;
            
            for(char &c : s) mask |= (1 << (c-'A'));
           
            dp[i][mask] = min(dp[i][mask], cst);

            for(int c = 0; c<8; c++ ){
                dp[i+1][c|mask] = min(dp[i+1][c|mask], dp[i][c] + cst);
                dp[i+1][c] = min(dp[i+1][c], dp[i][c]);
            }
        }
        if(dp[n][7] > 3e5) dp[n][7] = -1;

        cout << dp[n][7] << endl;
    }
    return 0;
}