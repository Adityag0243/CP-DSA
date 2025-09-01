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
//     // fastio;
//     int t = 1;
//     // cin >> t;
//     while(t--){
//         int n,k; cin >> n >> k;
//         vi v(n); l(i,0,n) cin >> v[i];
//         int a,b; cin >> a >> b;
        
//         // Using Gosper's Hack .....
//         int cnt = 0;
    
//         int sub = (1 << k) - 1;

//         while (sub <= (1 << n)) {
//             int sum = 0;
//             l(i,0,n) if( (sub >> i) & 1) sum += v[i];
//             if( sum >= a && sum <= b) cnt++;

//             //  it will do something and make sure to give a number with k bits on.... how I don't know..
//             int c = sub & - sub;
//             int r = sub + c;
//             sub = (((r ^ sub) >> 2) / c) | r;
//         }

//         cout << cnt << endl;

//     }
//     return 0;
// }