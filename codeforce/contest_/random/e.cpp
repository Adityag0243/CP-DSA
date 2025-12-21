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
#define MOD2            10007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

string s;
vector<vvi> dp(201, vvi(201, vi(1001, -1)) );

int fn(int i, int j, int op){
    if( i > j){
        return 1;
    }
    if( i == j){
        if( op >= 1) return 2;
        else return 1;
    }


    
    if( op < 0 ) return 0;

    if( dp[i][j][op] != -1) return dp[i][j][op] %= MOD2;

    if( s[i] == s[j] ){

        dp[i][j][op] = 26 * fn(i, j, op-2);

        if( i + 1 == j){
            if(op >= 1) dp[i][j][op] += 27;
            else dp[i][j][op] += 1;
        }
        else{
            dp[i][j][op] = fn(i+1, j-1, op) + fn(i+1, j, op-1) + fn(i, j-1, op-1);
        }

    }else{
        dp[i][j][op] = ( fn(i+1, j, op-1)  + fn(i, j-1, op-1) ) % MOD2;
    }

    dp[i][j][op] %= MOD2;
    return dp[i][j][op] %= MOD2;
}   

signed main(){
    cin >> s; 
    int n; cin >> n;
    int sz = s.size();
    n = min(n , 1000* 1ll);
    cout << fn(0, sz-1, n);    
    return 0;
}