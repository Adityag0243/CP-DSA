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

// // int min_index(vi &pos){
    
// //     if(pos[0] < min(pos[1], pos[2])) return 0;
// //     if(pos[1] < min(pos[0], pos[2])) return 1;
// //     return 2;   
// // }
// // int max_index(vi &pos){
// //     if(pos[0] > max(pos[1], pos[2])) return 0;
// //     if(pos[1] > max(pos[0], pos[2])) return 1;
// //     return 2;   
// // }
// // int second_min_ind(vi &pos){
// //     if(pos[0] > min(pos[1], pos[2])  && pos[0] < max(pos[1], pos[2])  ) return 0;
// //     if(pos[1] < min(pos[0], pos[2])  && pos[1] > min(pos[0], pos[2])) return 1;
// //     return 2;   
// // }

// int fn(set<pair<int, int>> & s){
//     int maxi = -1;
//     int mini = 1e6;
//     for(auto p : s){
//         maxi = max(maxi, -p.y);
//         mini = min(mini, -p.y);
//     }
//     return maxi - mini;

// }


// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         vi v(n); l(i,0,n) cin >> v[i];
//         l(i,0,n){
//             v[i] -= (n-i);
//             cout << v[i] << " \n"[i==n-1];
//         }
        
       
//         set<pair<int,int>> s;
//         s.insert({v[0],0});
//         s.insert({v[1],-1});
//         s.insert({v[2],-2});

//         int sum = 0;

//         for(auto p : s) sum += (p.x + (n + p.y));
//         int diff = fn(s);
//         int ans = sum - diff;

//         for(int i = 3; i<n; i++){
//             if( v[i] > (*s.begin()).x ){
//                 s.erase(s.begin());
//                 s.insert({v[i], -i});
//             }
//             sum = 0;
//             for(auto p : s) sum += (p.x + (n + p.y));
//             cout << sum << " " << ans << ", ";
//             diff = fn(s);
//             ans = max(ans, sum - diff);
//         }
//         cout << ans << endl;
//     }
//     return 0;
// }