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
//         int n,k; cin >>n >>k;
//         vi v(n); l(i,0,n) cin >> v[i];
//         int sum = smv(v);

//         while(k--){

//             priority_queue< pair<int,int> > pq;
            
//             if( n > 1 && v[1] < v[0] ) pq.push({v[0]-v[1], 0});
            
//             l(i,1,n-1){
//             pq.push( {max({0ll , v[i] - v[i+1], v[i] - v[i-1] }), i} );
//             }
//             if( n > 1 && v[n-1] > v[n-2]) pq.push({v[n-1] - v[n-2], n-1});

//             if( pq.empty() ) break;
//             sum -= pq.top().x;
//             int ind = pq.top().y;
//             v[ind] -= pq.top().x;
//         }

//         cout << sum << endl;


//     }
//     return 0;
// }