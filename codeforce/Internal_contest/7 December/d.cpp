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
#define float           double
signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<float> x(n);
        vector<int> t(n);
        l(i, 0, n) cin >> x[i];
        l(i, 0, n) cin >> t[i];

        float lo = mxv(t);  
        float hi = 5e8;     
        float ans = 0;     
        int cnt = 0;
        while (cnt++ < 10000  && hi - lo > 1e-6 ) {
            
            float mid = (hi + lo) / 2;
            float start = -1e9;
            float end = 1e9;

            
            l(i, 0, n) {
                start = max(start, x[i] - (mid - t[i]));
                end = min(end, x[i] + (mid - t[i]));
            }

            if (start <= end) { 
                ans = start;    
                hi = mid;       
            } else {
                lo = mid;        
            }
        }

        cout << fixed << setprecision(7) << abs(ans) << endl; 
    }
}
