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

// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         if(n == 1) cout << 1 << endl;
//         else if( n%5 == 0 || n%5 == 4 || n%5 == 1){
//             int m = -1;
//             if(n%5 == 1){
//                 m = n;
//                 n -= 6;
//             }
//             int cur = 0;
//             l(i,0,6){
//                 if(n == 0) break;
//                 n--;

//                 if(i % 5 == 0) i = 0;
//                 if(i & 1)   cur -= 2; 
//                 else        cur += 3;                
//                 cout << cur << " \n"[n == 0 && m == -1];
//             }
//             n = m-6;
//             if(m != -1){
//                 cout << n + 2 << " " << n + 5 <<" " << n + 3 <<" " << n+1 << " " << n+4 << " " << n + 6 << endl;
//             }
//         }
//         else cout << - 1 << endl;
//     }
//     return 0;
// }