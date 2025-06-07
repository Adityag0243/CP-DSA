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

//         vi mhreq(n);
//         mhreq[n-1] = h[n-1].y;
//         rl(i,0,n-1){
//             mhreq[i] = min(mhreq[i+1], h[i].y);
//         }

//         vi mnhreq(n);
//         mnhreq[n-1] = h[n-1].x;
//         rl(i,0,n-1){
//             mnhreq[i] = min( mnhreq[i+1], h[i].x);
//         }
    

//         ch = 0;
//         l(i,0,n)
//         {
//             if(d[i] != -1){
//                 ch += d[i];
//                 if(ch < mnhreq[i] || ch > mhreq[i] || ch < h[i].x || ch > h[i].y ){
//                     flag = false;
//                     break;
//                 }
//             }else{  
//                 if( ch + 1 <= mhreq[i] && ch + 1 >= mnhreq[i]  && ch+1 >= h[i].x && ch+1 <= h[i].y){
//                     ch++;
//                     d[i] = 1;
//                 }else if(ch <= mhreq[i] && ch >= mnhreq[i]  && ch >= h[i].x && ch <= h[i].y ){
//                     d[i] = 0;
//                 }else{
//                     flag = false;
//                     break;
//                 }
//             }
//             // cout << i <<" ";
//         }
//         //  for( int x : d) cout << x << " ";
//         //  cout << endl;
//         if(flag) for( int x : d) cout << x << " ";
//         else cout << -1;


//         cout << endl;


//     }
//     return 0;
// }