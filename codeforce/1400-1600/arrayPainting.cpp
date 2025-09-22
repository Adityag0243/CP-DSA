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
//     int t = 1;
//     // cin >> t;
//     while(t--){
//         int n; cin >> n;
//         vi vi_(n+1); l(i,1,1+n) cin >> vi_[i];
//         vi v; v.pb(0ll);
//         l(i,1,1+n){
//             if(vi_[i] == 0) v.pb(0ll);
//             if(vi_[i] != vi_[i-1]) v.pb(vi_[i]);
//         }
//         n = v.size();
//         vi isr(n+2);
//         int c = 0;

//         l(i,1,1+n){
//             if(v[i] == 2 && isr[i] == 0){
//                 isr[i] = 1;
//                 isr[i-1] = 1;
//                 isr[i+1] = 1;
//                 c++;
//             }
//         }
//         // cout << c << " 1st\n";
//         // l(i,1,n+1) cout << isr[i]<< " \n"[i==n];
//         // l(i,1,1+n){
//         //     if(isr[i] == 1){
//         //         if(v[i] == 1){
//         //             if(v[i-1] == 1 && isr[i-1] == 0) isr[i-1] = 1;
//         //             else if(v[i+1] == 1 && isr[i+1] == 0) isr[i+1] = 1;
//         //             else if(isr[i-1] == 0) isr[i-1] = 1;
//         //             else isr[i+1] = 1;
//         //         }else if(v[i] == 2){
//         //             isr[i+1] = 1;
//         //             isr[i-1] = 1; 
//         //         }
//         //     }
//         // }
//         // l(i,1,n+1) cout << isr[i]<< " \n"[i==n];
//         // l(i,1,n+1){
//         //     if(isr[i] == 0 && v[i] == 1){
//         //         isr[i] = 1;
//         //         c++;
//         //         if(v[i-1] == 1 && isr[i-1] == 0) isr[i-1] = 1;
//         //         else if(v[i+1] == 1 && isr[i+1] == 0) isr[i+1] = 1;
//         //         else if(isr[i-1] == 0) isr[i-1] = 1;
//         //         else isr[i+1] = 1;
//         //     }
//         // }
//         // cout << c << " 2nd\n";
//         // l(i,1,n+1) cout << isr[i]<< " \n"[i==n];
        
//         // l(i,1,1+n){
//         //     if(isr[i] == 0) c++;
//         // }
//         cout << c << endl;


//     }
//     return 0;
// }