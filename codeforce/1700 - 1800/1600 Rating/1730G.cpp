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


vi p2(32);
void pre(){
    p2[0] = 1;
    l(i,1,32) p2[i] = 2 * p2[i-1]; 
}

int n,k;
vi v(100005);

int fn(int i, int f, vvi &dp){
    if( i == n) return 0;
    if(dp[i][f] != -1e16) return dp[i][f];

    if( (v[i]/p2[f]) >= 2*k ) return dp[i][f] = (v[i]/p2[f]) - k  + fn(i+1, f, dp);
    else{
        int op1 = (v[i]/p2[f]) - k + fn(i+1, f, dp);
        int op2 = 0;
        if(f < 31) op2 = (v[i]/p2[f+1]) + fn(i+1, f+1, dp);

        return dp[i][f] = max(op1, op2);
    }
}


signed main(){
    pre();
    fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        l(i,0,n) cin >> v[i];
        vvi dp(n, vi(32, -1e16));
        cout << fn(0,0, dp) << endl;
    }
    return 0;
}