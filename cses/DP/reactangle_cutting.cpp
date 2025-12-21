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

int n,m;
vvi dp(501, vi(501, -1));

int fn(int i, int j){
    if( i == j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = i+j;
    // horizontal cuts
    for(int r = 1; r < i; r++){
        ans = min(ans, 1 + fn(r,j) + fn(i-r, j));
    }
    // vertical cuts
    for(int c = 1; c < j; c++){
        ans = min(ans, 1 + fn(i,c) + fn(i, j-c));
    }

    return dp[i][j] = dp[j][i] = ans;
}

signed main(){
    cin >> n >> m;
    cout << fn(n,m);
    return 0;
}