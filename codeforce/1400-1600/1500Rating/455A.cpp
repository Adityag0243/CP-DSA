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

signed main(){
    int n;
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];
    map<int,int> mp;
    l(i,0,n) mp[v[i]]++;
    
    vector< pair<int,int> > dp;
    for( auto it : mp ){
        int val = it.x * it.y;
        dp.pb({it.x,val});
    }

    for(int i = 0; i<dp.size(); i++){
        if(i-1 >= 0  && dp[i-1].x != dp[i].x - 1 )
        {
            dp[i].y = dp[i].y + dp[i-1].y; 
        }
        if( i-2 >=0 ){
            dp[i].y = max(dp[i].y, (dp[i].x * mp[dp[i].x])  + dp[i-2].y); 
        }
        if( i-3 >=0 ){
            dp[i].y = max(dp[i].y, (dp[i].x * mp[dp[i].x])  + dp[i-3].y); 
        }
    }
    int ans = 0;
    for(auto it : dp){
        // cout << it.y <<" ";
        ans = max( ans, it.y);
    }

    cout << ans << endl;

    return 0;
}