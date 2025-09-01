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




double lrSum(vector<double> &pref, int l, int r){
    if(l <= 0) return pref[r];
    else return pref[r] - pref[l-1];
}

double fn(int n, int a, int b, vector<double> &dp, int minus){
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];
 
    double ans;
    if (a == 0) {
        double total = 0;
        for (int i = 1; i <= b; i++) {
            total += fn(n - i, a, b, dp);
        }
        ans = ( (double)(b+1) / (double)b ) + total / (double)b;
    } else {
        double total = 0;
        for (int i = a; i <= b; i++) {
            total += fn(n - i, a, b, dp);
        }
        ans = 1.0 + total / (double)(b - a + 1);
    }
    return dp[n] = ans;
}

signed main(){
    // fastio;
    int t = 1;
    // cin >> t;
    while(t--){
        int n,a,b; cin >> n >> a >> b;
        len = n;
        vector<double> dp(n+1, -1);
        cout << fixed <<setprecision(6) <<fn(n,a,b,dp, 1);
    }
    return 0;
}