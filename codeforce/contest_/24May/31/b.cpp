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
#define mod         998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int power(int x) {
    if (x == 0) return 1;
    int val = power(x / 2);
    val = (1LL * val * val) % mod;
    if (x % 2 == 0) return val;
    else return (2LL * val) % mod;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi a(n); l(i,0,n) cin >> a[i];
        vi b(n); l(i,0,n) cin >> b[i];

        // cout <<"Done  ";
        vi prei(n);
        l(i,0,n) prei[i] = i;

        l(i,1,n){
            if( a[prei[i-1]] > a[prei[i]] ) prei[i] = prei[i-1];
        }

        // cout <<"Here ";

        vi prej(n);
        l(i,0,n) prej[i] = i;

        l(i,0,n) prej[i] = i;
        l(i,1,n){
            if( b[prej[i-1]] > b[prej[i]] ) prej[i] = prej[i-1];
        }

        // for(int x : prei) cout<<x << " ";
        // cout << endl;
        // for(int x : prej) cout<<x << " ";
        // cout << endl;


        vi ans;

        l(i,0,n){
            if( a[prei[i]] > b[prej[i]] ){
                ans.pb(  ( power(a[prei[i]]) + power(b[i-prei[i]]) )%mod );
            }else if(a[prei[i]] < b[prej[i]]){
                ans.pb(  ( power(b[prej[i]]) + power(a[i-prej[i]]) )%mod );
            }else{
                if( a[prei[i]] + b[i-prei[i]]   > b[prej[i]] + a[i-prej[i]] ){
                    ans.pb(  ( power(a[prei[i]]) + power(b[i-prei[i]]) )%mod );
                }else{
                    ans.pb(  ( power(b[prej[i]]) + power(a[i-prej[i]]) )%mod );
                }
            }
        }

        l(i,0,n) cout << ans[i] << " \n"[i==n-1];
    
    
    }
    return 0;
}