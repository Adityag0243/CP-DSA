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

int n;
bool isValid(int i, int j){
    return ( i < n && i >= 0 && j < n && j >= 0);
}

signed main(){
    cin >> n;
    vvi dp(n, vi (n));
    vector<string> vs(n);
    l(i,0,n) cin >> vs[i];

    if(vs[0][0] == '.' && vs[n-1][n-1] == '.') dp[0][0] = 1;

    l(i,0,n){
        l(j,0,n){
            if( vs[i][j] == '*' ) continue;
            if( isValid(i-1,j) ) dp[i][j] += dp[i-1][j];
            if( isValid(i,j-1) ) dp[i][j] += dp[i][j-1];
            dp[i][j] %= MOD2;
        }
    }
    
    cout << dp[n-1][n-1];
    return 0;
}