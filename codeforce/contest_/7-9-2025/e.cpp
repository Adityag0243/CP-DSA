// #include <bits/stdc++.h>
// using namespace std;
// #define all(v)        v.begin(), v.end()
// #define vi              vector<int>
// #define vvi             vector<vi>
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// // #define p(x)            cout << (x) << endl;
// #define sp(x)           cout << (x) << " ";
// #define endl            '\n'
// #define pb              push_back
// #define mxv(v)        *max_element(v.begin(), v.end())
// #define mnv(v)        *min_element(v.begin(), v.end())
// #define smv(v)        accumulate(v.begin(), v.end(), 0LL)
// #define srt(v)        sort(v.begin(), v.end())
// #define rev(v)        reverse(all(v))
// #define MOD2            1000000007
// #define x               first
// #define y               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



// int fn(vector<int>& v) {
//     int n = v.size();
//     vector<bool> p(n+2, false);

//     for (int &x : v) {
//         if (x <= n) p[x] = true;
//     }
//     for (int i = 0; i <= n+1; i++) {
//         if (!p[i]) return i;
//     }
//     return n+1; 
// }


// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n,k; cin >> n >> k;
       
//         map<int,int> f;
//         vi v(n);
//         l(i,0,n){
//             cin >> v[i];
//             f[v[i]]++;
//         }
//         int mex = fn(v);
        

//         int nmex = mex;
//         l(i,0,n){
//             if(v[i] < mex && f[v[i]] > 1) nmex = min(nmex, v[i]);
//         }
//         // cout << "nmex : " << nmex << " :    ";
//         if(k == 1){
//             int sum = 0;
//             l(i,0,n){
//                 if(v[i] > mex ) sum += mex;
//                 else{
//                     if(f[v[i]] == 1) sum += v[i];
//                     else sum += mex;
//                 }
//             }
//             cout << sum << endl;
//         }else{

          
//             int sume = 0, sumo = 0;
//             l(i,0,n){
//                 if(v[i] > nmex ){
//                     sume += nmex;
//                     sumo += (nmex+1);
//                 }
//                 else{
//                     if(f[v[i]] == 1){
//                         sume += v[i];
//                         sumo += v[i];
//                     }
//                     else{
//                         sume += nmex;
//                         sumo += (nmex+1);
//                     }
//                 }
//             }

//             if( nmex == mex ) cout << ((k & 1  ) ? sume : sumo) << endl;
//             else    cout << ((k & 1) ? sumo : sume) << endl;
//         }


//     }
//     return 0;
// }