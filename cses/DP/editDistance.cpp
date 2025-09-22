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

string a,b; 
int n,m;

int fn(int i, int j, vvi &dp){
    if( i >= n ) return m-j;
    if( j >= m ) return n-i;
    if(dp[i][j] != -1) return dp[i][j];


    int op1 = (a[i] != b[j]) + fn( i+1, j+1, dp);
    int op2 = 1 + fn( i, j+1, dp );
    int op3 = 1 + fn( i+1, j, dp );

    return dp[i][j] = min({ op1, op2, op3 });
}


signed main(){
    cin >> a >> b;
    n = a.size(); 
    m = b.size();
    vvi dp(n, vi(m, -1));

    cout << fn(0,0,dp);

    return 0;
}