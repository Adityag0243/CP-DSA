// #include <bits/stdc++.h>
// using namespace std;
// #define all(arr)        arr.begin(), arr.end()
// #define vi              vector<int>
// #define vvi             vector<vi>
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// #define p(x)            cout << (x) << endl;
// #define sp(x)           cout << (x) << " ";
// #define endl            '\n'
// #define pb              push_back
// #define mxv(arr)        *max_element(arr.begin(), arr.end())
// #define mnv(arr)        *min_element(arr.begin(), arr.end())
// #define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
// #define srt(arr)        sort(arr.begin(), arr.end())
// #define rev(arr)        reverse(all(arr))
// #define MOD2            1000000007
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


// struct VecHash {
//     size_t operator()(const vector<int>& v) const {
//         size_t h = 0;
//         for (int x : v) {
//             h ^= hash<int>()(x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2));
//         }
//         return h;
//     }
// };

// int total = 0;

// int fn(int i,vi &v, vi &a, vi &b, map<vi, int, VecHash>&dp, vi &done, int ai, int bi, vi &till_now){
//     int n = v.size();
//     if( ai == 1+n || bi == 1+n) return 0;
//     // bob 


//     // alice 
//     while(done[a[ai]]) ai++;
//     if(ai <= n){
//         till_now.pb(v[a[ai]]);
//         done[v[a[ai]]] = 1;
//         dp[till_now] = total - fn()
//     }

    


// }

// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         vi v(n+1); l(i,1,1+n) cin >> v[i];
//         vi a(n+1); l(i,1,1+n) cin >> a[i];
//         vi b(n+1); l(i,1,1+n) cin >> b[i];
//         total = smv(v);
//         vi done(n+1);
//         map<vi, int, VecHash> dp;
//         cout << fn(1ll,v,a,b,dp,done, 1ll, 1ll, {});
//     }
//     return 0;
// }