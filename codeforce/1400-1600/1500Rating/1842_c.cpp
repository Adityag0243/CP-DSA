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
        int n; cin>> n;
        vector<int> v(n);
        l(i,0,n) cin >> v[i];


        // min no of ele I won't be able to delete till i...
        vector<int> dp(n);
        dp[0] = 1;
        
        // for any value val what is the minimum previous element I won't able to delete..
        map<int, int> mp;
        
        mp[v[0]] = 0;

        l(i,1,n){
            if( mp.find(v[i]) != mp.end() ){
                dp[i] = min(dp[i-1]+1, mp[v[i]]);
                mp[v[i]] = min(mp[v[i]], dp[i-1]);
            }else{
                mp[v[i]] = dp[i-1];
                dp[i] = dp[i-1]+1;
            }

        }
        for(int x : dp) cout<<x<<" ";


        cout << n - dp[n-1] << endl;
    }
    return 0;
}