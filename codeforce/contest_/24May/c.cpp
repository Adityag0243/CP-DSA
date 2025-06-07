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
//         vi d(n); l(i,0,n) cin >> d[i];
//         vector<pair<int,int>> h(n);
//         l(i,0,n) cin >> h[i].x >> h[i].y;

//         vi need(n);
//         int lead = 0;
//         vi canAdd(n);

//         int ch = 0;
//         bool flag = true;


//         l(i,0,n){

//             if( d[i] != -1){
//                 ch += d[i];
//                 if(ch + lead >= h[i].x  && ch <= h[i].y){
//                     lead -= max(0ll, h[i].x - ch);
//                     need[i] = max(0ll, h[i].x - ch);
//                     ch = max(ch,h[i].x);
//                 }
//                 else flag = false;

//             }else{

//                 if( ch+1 <= h[i].y){
//                     lead++;
//                     canAdd[i] = 1;
//                 }

//                 if(ch + lead >= h[i].x  && ch <= h[i].y){
//                     lead -= max(0ll, h[i].x - ch);
//                     need[i] = max(0ll, h[i].x - ch);
//                     ch = max(ch,h[i].x);
//                 }
//                 else flag = false;
                
//             }
//         }

//         int req = smv(need);
//         ch = 0;
//         l(i,0,n){
//             if(req <= 0) break;
//             if(d[i] != -1){
//                 ch += d[i];
//             }else{
//                 if(ch + 1 <= h[i].y && ch+1 >= h[i].x){
//                     req--;
//                     ch++;
//                     d[i] = 1;
//                 }else d[i] = 0;
//             }
//         }

//         if(req > 0) flag = false;

        

//         if(flag) for( int x : d) cout << x << " ";
//         else cout << -1;


//         cout << endl;


//     }
//     return 0;
// }