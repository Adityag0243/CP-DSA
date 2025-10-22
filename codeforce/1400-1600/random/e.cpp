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
        int n,k,l,r; cin >> n >> k >> l >> r;
        vi v(n); l(i,0,n) cin >> v[i];
        map<int,int> mp;

        int i = 0, j = 0;
        int cnt = 0;
        int ans = 0;

        while( i < n && j < n ){
            mp[v[j]]++; cnt++; j++;
            
            while(cnt > r){
                mp[v[i]]--;
                if( mp[v[i]] == 0 ) mp.erase(v[i]);
                i++; cnt--;
            }

            while( mp.size() == k && cnt >= l && cnt <= r ){
                ans++;
                mp[v[i]]--;
                if( mp[v[i]] == 0 ) mp.erase(v[i]);
                i++; cnt--; 
            }
        }

        cout << ans << endl;
    }
    return 0;
}