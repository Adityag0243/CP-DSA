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
//     int n; cin >> n;
//     vector<pair<int,int>> canvas(n);
//     l(i,0,n){
//         cin >> canvas[i].x >> canvas[i].y;
//     }
//     srt(canvas);

//     int p; cin >> p;
//     vector<int> clip_pos(p);
//     l(i,0,p) cin >> clip_pos[i];
//     srt(clip_pos);

//     vector<set<int>> ind_to_clip(n);
//     int i = 0;
//     for( int cp : clip_pos){
//         while( i < n && canvas[i].y < cp) i++;

//         if( i < n && canvas[i].x <= cp && canvas[i].y >= cp){
//             ind_to_clip[i].insert(cp);
//         }
//         if( i+1 < n && canvas[i+1].x <= cp && canvas[i+1].y >= cp){
//             ind_to_clip[i+1].insert(cp);
//         }
//     }

//     bool flag = false;
//     for( auto it : ind_to_clip){
//         if(it.size() > 2) flag = true;
//     }

//     if(flag)  cout << "impossible";
//     else{
//         set<int> ans;
//         l(i,0,n){
//             int l = canvas[i].x;
//             int r = canvas[i].y;
//             if( ind_to_clip[i].size() == 0 ){
//                 ans.insert(l);
//                 ans.insert(r);
//             }else if( ind_to_clip[i].size() == 1){
//                 if( *(ind_to_clip[i].begin()) != r){
                    
//                     if( i+1 < n && canvas[i+1].x == r && ind_to_clip[i+1].size() < 2 ){
//                         ans.insert(r);
//                         ind_to_clip[i+1].insert(r);
//                     }else{
//                         ans.insert(r-1);
//                     } 
//                 }else{
//                     ans.insert(l+1);
//                 }
//             }
//         }

//         cout << ans.size() << endl;
//         for(int pos : ans ) cout << pos << " ";
//         cout << endl;
//     }


//     return 0;
// }