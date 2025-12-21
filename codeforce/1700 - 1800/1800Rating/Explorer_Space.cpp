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

int n,m,k;
vvi nextcol(501, vi(500));
vvi nextrow(501, vi(500));
vector<vvi> dp(
    500, vvi(
        500, vi(
            21, -2
        )
    )
);

int fn( int i, int j, int k){
    if( k & 1) return -1;
    if( k == 0) return 0;
    if( dp[i][j][k] != -2) return dp[i][j][k];
    int c = 1e15;
    if( i-1 >= 0 ) c = min( c, 2*nextrow[i-1][j] + fn( i-1, j, k-2));  
    if( i+1 <  n ) c = min( c, 2*nextrow[i][j]   + fn( i+1, j, k-2));  
    if( j+1 <  m ) c = min( c, 2*nextcol[i][j]   + fn( i, j+1, k-2));  
    if( j-1 >= 0 ) c = min( c, 2*nextcol[i][j-1] + fn( i, j-1, k-2));
    
    return dp[i][j][k] = c;
}



signed main(){
    cin >> n >> m >> k;
    l(i,0,n) l(j,0,m-1) cin >> nextcol[i][j];
    l(i,0,n-1) l(j,0,m) cin >> nextrow[i][j];

    l(i,0,n) l(j,0,m) cout << fn(i,j,k) << " \n"[j==m-1];
    return 0;
}