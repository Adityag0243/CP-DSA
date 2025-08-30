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


int fn(vi &v, int i, int ts, vi &dp){
    if(i == v.size()) return 0;

    if(dp[i] == -1){

        int one = ts - fn(v, i+1, ts-v[i], dp);
        int two = fn(v, i+1, ts-v[i], dp);
        dp[i] = max(one, two);  
    }

    return dp[i];
}

signed main(){
    int n; cin >> n;
    vi v(n); l(i,0,n) cin>> v[i];
    int ts = smv(v);
    vector<int> dp(n, -1);

    int bob = fn(v,0,ts,dp);
    cout <<  ts - bob << " " << bob;
    return 0;
}