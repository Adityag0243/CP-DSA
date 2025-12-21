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
vi v;
vector<vector<int>> dp(3001, vi (3000, -1));

int fn(int i, int j, int ts){
    if( i > j) return 0;
    if( dp[i][j] != -1) return dp[i][j];

    int op1 = ts - fn(i+1, j, ts-v[i]);
    int op2 = ts - fn(i, j-1, ts-v[j]);

    return dp[i][j] =  max(op1, op2);
}

signed main(){
    cin >> n;
    v.resize(n);
    l(i,0,n) cin >> v[i];

    int x = fn(0,n-1, smv(v));
    cout << x - (smv(v)-x);
    return 0;
}