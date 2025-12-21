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



signed main(){
    cin >> n >> m;
    vvi v(n, vi(m, -1));
    l(i,0,n) l(j,0,m) cin >> v[i][j];
    vvi dp(n+1, vi(1025, -1));

    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m ; j++){
            if(i == 0){    
                dp[i][v[i][j]] = j;  // base values from row 1 
            }else{
                l(mask, 0, 1024){
                    if(dp[i-1][mask] != -1){
                        dp[i][mask ^ v[i][j]] = j;
                    }
                }
            }
        }
    }


    int mask = 0;
    l(b, 1, 1024)if(dp[n-1][b] >= 0) mask = b;
    if(mask){
        cout << "TAK\n";
        vi ans;
        rl(i,0,n){
            ans.pb(dp[i][mask]);  // index of backtrack...
            mask ^= v[i][dp[i][mask]];
        }    
        
        reverse(all(ans));
        for( int x : ans ) cout << x + 1 << " ";

    }else{
        cout << "NIE";
    }
    return 0;
}