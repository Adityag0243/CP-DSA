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
//         int n,m,a; cin >> n >> m;
//         vi anm[n+1];
//         vi vm(m+1);
//         vm[0] = 1;

//         l(i,0,n){
//             int sz; cin >> sz;
//             l(j,0,sz){
//                 cin >> a;
//                 anm[i].pb(a);
//                 vm[a]++;
//             }
//         }

//         if( mnv(vm) == 0){
//             no
//             continue;
//         }

//         vi vmc = vm;
//         int c = 0;
//         l(i,0,n){
//             bool flag = true;
//             for( int val : anm[i]){
//                 if( vm[val] == 1){
//                     flag = false;
//                     break;
//                 }
//             }
//             if(!flag) continue;
//             for( int val : anm[i]){
//                 c++;
//                 vm[val]--;
//             }
//         }
        

//         if(mnv(vm) > 0 && c >= 2) yes
//         else no
//     }
//     return 0;
// }