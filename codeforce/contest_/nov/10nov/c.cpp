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
        int n;
        cin >> n;
        vector<int> v1(n+1),v2(n+1);
        for(int i = 1; i <= n ; i++) cin >> v1[i]; 
        for(int i = 1; i <= n ; i++) cin >> v2[i]; 

        vector<int> pmn(n+1, 2e9), pmx(n+1, -2e9);
        for(int i = 1; i <= n; i++ ){
            pmn[i] = min(v1[i], pmn[i-1]);
            pmx[i] = max(v1[i], pmx[i-1]);
        }

        vector<int> smn(n+2, 2e9), smx(n+2, -2e9);
        for(int i = n; i >= 1; i--){
            smn[i] = min(v2[i], smn[i+1]);
            smx[i] = max(v2[i], smx[i+1]);
        }

        vector<int> lrs(2*n+1, 2*n+1);
        
        for(int i = 1; i <= n; i++){
            int mn = min( pmn[i], smn[i] );
            int mx = max( pmx[i], smx[i] );
            lrs[mn] = min( lrs[mn], mx );
        }
        for(int i = 2*n-1; i >= 1; i--){
            lrs[i] = min(lrs[i], lrs[i+1]); // [1,10] [3,8...] ==> [1,8] [2,8] [3,8]
        }

        int ans = 0;
        for(int i = 1; i <= 2*n; i++){
            ans += ( (2*n - lrs[i] + 1) );
        }

        cout << ans << endl;        
    }
    return 0;
}