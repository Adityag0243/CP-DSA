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
vvi v;

vvi fn(int row, int col, int rop, int cop){
    vvi dp(n, vi(m));
    for(int i = row; (i >= 0 && i < n); i += rop){
        for(int j = col; (j >= 0 && j < m); j += cop){
            int a = 0, b = 0;
            if(i-rop >= 0 && i-rop <n) a = (dp[i-rop][j]);
            if(j-cop >= 0 && j-cop <m) b = (dp[i][j-cop]);
            dp[i][j] = max( a , b) + v[i][j];
        }
    }
    return dp;
}


signed main(){
    cin >> n >> m;
    v.resize(n, vi(m));
    l(i,0,n) l(j,0,m) cin >> v[i][j];
    vvi dp1 = fn(0,0,1,1);  // tl
    vvi dp2 = fn(0,m-1,1,-1); // tr
    vvi dp3 = fn(n-1,m-1,-1,-1); // br
    vvi dp4 = fn(n-1,0,-1,1); //bl
    

    int ans = 0;
    // all four direction will come to i,j   each can come from 2 ways 16 possibility
    // but they are interlinked if tl is above i,j then tr must be on right of i,j then br must be below ans so on
    // it make 2 valid ways out of 16 ways.....
    l(i,1,n-1) l(j,1,m-1){
        ans = max(ans, dp1[i-1][j] + dp2[i][j+1] + dp3[i+1][j] + dp4[i][j-1] - 4*v[i][j]);
        ans = max(ans, dp1[i][j-1] + dp2[i-1][j] + dp3[i][j+1] + dp4[i+1][j] - 4*v[i][j]);
    }

    cout << ans;
    
    return 0;
}