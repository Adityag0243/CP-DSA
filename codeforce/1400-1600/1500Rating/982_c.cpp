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
//     int n;
//     cin >> n;
//     vector<int> inDegree(n);
//     // vector<pair<int,int>> vp;
//     vvi adj(n);
//     l(i,1,n){
//         int a,b;
//         cin >> a >> b;
//         a--;
//         b--;
//         adj[a].pb(b);
//         adj[b].pb(a);
//         inDegree[a]++;
//         inDegree[b]++;
//     }

//     if(n & 1) cout << -1 ;
//     else{
//         // l(i,0,n) cout << inDegree[i] << " ";
//         int cnt = 0;
//         l(i,0,n){
//             if(inDegree[i] == 1) continue;

//             int one = 0;
//             int zero = 0;
//             for( auto x : adj[i] ){
//                 if( inDegree[x] == 1) one++;
//                 else if( inDegree[x] == 0) zero++;
//             }
            
            
//             int sz = adj[i].size();
//             if( inDegree[i] % 2 == 0 ){
//                 if( (sz - one + zero )% 2 == 0) cnt += max(0ll, sz - one - zero);
//                 else cnt += max(0ll, sz - one - 1 - zero );
//             }else{
//                 if( (sz - one + zero )% 2 == 0) cnt += max(0ll, sz - one - 1 - zero);
//                 else cnt += max(0ll, sz - one - zero);
//             }
//             inDegree[i] = 0;
//         }
//         cout << cnt << endl;
//     }
//     return 0;
// }