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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vi b(n+1); l(i,1,n+1) cin >> b[i];
        map< pair<int,int>, int> mp;

        l(i,0,m){
            int s,t,w;
            cin >> s >> t >> w;

            if( mp.find({s,t}) != mp.end()){
                mp[{s,t}] = min(w, mp[{s,t}]);
            }else{
                mp[{s,t}] = w;
            }
        }

        vector<pair<int,int>> dp(n+1, {INT_MAX,INT_MIN});
        l(i,1,n+1) dp[i].y = b[i];
        dp[1] = {0, b[1]};

        for( auto it : mp){
            int cur_pos = it.x.x;
            int dest_pos = it.x.y;
            int cost = it.y;
            
            if( dp[cur_pos].y >= cost ){
                if( dp[cur_pos].x < cost) dp[cur_pos].x = cost;
                dp[dest_pos].x  = min( dp[dest_pos].x, dp[cur_pos].x);
                dp[dest_pos].y  = max( dp[dest_pos].y, b[dest_pos]+dp[cur_pos].y);
            } 

        }

        for( auto it : dp) cout <<"(" <<it.x << ", " << it.y << ") ";

        if(dp[n].x == INT_MAX) dp[n].x = -1;
         cout << dp[n].x << endl;
    }
    return 0;
}