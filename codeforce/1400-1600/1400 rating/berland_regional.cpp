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
        int n; cin >> n;
        vi u(n); l(i,0,n) cin >> u[i];
        vi s(n); l(i,0,n) cin >> s[i];

        map<int, vector<int>> mp;
        l(i,0,n){
            mp[u[i]].pb(s[i]);
        }
        vi ans(n+1);

        for( auto &it : mp){
            auto &vec = it.second;  
            int m = vec.size();

            sort(vec.rbegin(), vec.rend());
            vector<int> pref(m + 1, 0); // 1 based........
            for (int i = 0; i < m; i++) pref[i + 1] = pref[i] + vec[i];

            for(int k = 1; k<=m ; k++){  // m only...   (very important....)
                int usable = m - m%k;
                ans[k] += pref[usable];  // as pref is 1 based otherwise usable-1
            }

        }

       
        l(i,1,1+n) cout << ans[i] << " ";
        cout << endl;
        
    }
    return 0;
}