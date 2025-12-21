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
// #define MOD2            998244353
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// vi f(100001);
// vi invf(100001);
// int power(int a, int b) {
//     int val = power(a,b/2);
//     val = (val * val) % MOD2;
//     if(b & 1) return (val * a) % MOD2;
//     return val;
// }

// void pre() {
//     f[0] = 1;
//     for (int i = 1; i < 100001; i++)
//         f[i] = (f[i - 1] * i) % MOD2;

//     invf[100000] = power(f[100000], MOD2 - 2); 
//     for (int i = 99999; i >= 0; i--)
//         invf[i] = (invf[i + 1] * (i + 1)) % MOD2;
// }

// int ncr(int n, int r) {
//     if (r < 0 || r > n) return 0;
//     return f[n] * invf[r] % MOD2 * invf[n - r] % MOD2;
// }




// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         vi v(n); l(i,0,n) cin >> v[i];
//         bool flag = true;

//         int up = n;
//         l(i,0,n/2){
//             // if(v[i] == 0) continue;
//             if(v[i] >= 2  && v[i] <= up){}
//             else flag = false;
//             up -= 2;
//         }
//         if(n & 1) if(v[n/2] != 1) flag = false;
//         int st = n/2;
//         if(n&1) st++;

//         int val = 3;
//         for(int i = st; i<n ; i++){
//             if(v[i] == 0) continue;
//             if(v[i] > val || v[i] < 2) flag = false;
//             val += 2;
//         }

//         if(flag){
//             cout << "here... ";
//             int ans = 1;
//             up = n;
//             for(int i = 0; i<n/2; i++){
//                 ans = (ans * ncr(up-2, v[i]-2)) % MOD2;
//                 up -= 2;
//             }

        
//             val = 3;
//             for(int i = st; i<n ; i++){
//                 if(v[i] == 0) continue;
//                 ans = (ans * ncr(val-2, v[i]-2))% MOD2;
//                 val += 2;
//             }
//         }else{
//             cout << 0 << endl;
//         }
        
//     }
//     return 0;
// }