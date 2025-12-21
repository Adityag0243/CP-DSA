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
        vi v(n); for( int &i : v) cin >> i;
        
        bool flag = (v[0] == -1);

        int ans = 0;
        l(i,1,n-1) if(v[i] == -1) v[i] = 0;
        l(i,1,n-2) ans += (v[i+1] - v[i]);
        // cout << ans << " ";

        if( v[n-1] == -1){
            
            if(v[0] == -1) v[0] = 0;
            if(n > 1){
                if( ans >= 0 ){
                    v[n-1] = 0;
                }else{
                    v[n-1] = v[n-2]+abs(ans);
                }
            }
        }else if( v[0] == -1){
            // cout << "yes   ";
            if( ans >= 0 ){
                v[0] = v[1] + ans;
            }else{
                v[0] = 0;
            }

        }

        if(n > 1){
            ans += v[1]-v[0];
            if(n > 2)ans += v[n-1] - v[n-2];
        }

        cout << abs(ans) << endl;
        for(int x : v) cout << x << " ";
        cout << endl;

       
        
        


    }
    return 0;
}