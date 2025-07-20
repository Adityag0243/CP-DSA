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

// int power(int base, int p){
//     if( p == 0) return 1;
//     if( p == 1) return base;

//     int val = power(2, p/2);
//     val = (val * val) % MOD2;
//     if( p % 2 == 0){
//         return val;
//     }else{
//         return (val * 2)% MOD2;
//     }

//     return val;
// }


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];
        int val = v[0];
        l(i,0,n) val &= v[i];

        int f = 0;
        l(i,0,n) if( v[i] == val) f++;
        if( f < 2){
            cout << 0 << endl;
            continue;
        }
        
        int ans = 1;
        for(int i = 2; i <= n-2; i++) ans = (ans * i)% MOD2;
        ans %= MOD2;

        // fC2 * 2  == f * f-1
        ans =  (ans * ( (f * (f - 1)) % MOD2)) % MOD2;
        cout << ans << endl;
    }

    return 0;
}