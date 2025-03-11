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
#define mod             998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int fn(vector<int> &v, int i, bool prev_status, int total_lier,vector<vector<int>> &dp ){
    if(prev_status == false && v[i] != total_lier) return 0;
    
    if( i == v.size()-1 ){
        if(prev_status == true && v[i] == total_lier) return 2;
        return 1;
    }
    if(dp[i][prev_status ? 0 : 1] != -1) return dp[i][prev_status ? 0 : 1];
    int cnt = 0;

    if(v[i] == total_lier) cnt += fn(v, i+1, true, total_lier, dp);
    if(prev_status == true) cnt += fn(v, i+1, false, 1 + total_lier, dp);

    dp[i][prev_status ? 0 : 1] = cnt % mod;
    return cnt%mod;
}


signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];
        
        vector<vector<int>> dp(n, vector<int>(2, -1));
        cout << fn(v,0,true,0,dp) << endl;
        
        
    }
}