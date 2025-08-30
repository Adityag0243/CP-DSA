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
        vector<long long> v(n+1); l(i,1,n+1) cin >> v[i];
        long long ans = 0;

        l(i,1,n+1){
            if(i % 2 == 1){
                int nv = v[i];
                if(i - 1 > 0) nv = min(v[i-1], nv);
                if(i + 1 <= n) nv = min(nv, v[i+1]);
                if( v[i] > nv){
                    ans += v[i]-nv;
                    v[i] = nv;
                }
            }else{
                int sum = 0;
                if(i - 1 > 0) sum += v[i-1];
                if(i + 1 <= n) sum += v[i+1];

                if(i+1 <= n && sum > v[i]){
                    ans += (sum - v[i]);
                    if(i+1 <= n)v[i+1] -= (sum-v[i]);
                }

            }
             

            // cout << ans << " ";
        }
        cout << ans << endl;
    }
    return 0;
}