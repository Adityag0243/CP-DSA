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


// int fn(vi & vr, vi & vb, vi &vg, int ans){
//     int r = vr.size();
//     int b = vb.size();
//     int g = vg.size();
//     for(int i = 0; i<r ; i++){
//         int j = lower_bound( all(vb), vr[i]) - vb.begin();
//         // lower bound >= vr[i]   we will consider j and j-1 index value which is near to vr[i]
//         for( int ind = -1; ind < 1; ind++){   // j-1 and j
//             if( j + ind >= 0 && j+ind <= b){
//                 int k = lower_bound( all(vg), vb[j+ind]) - vg.begin();
//                 //  again we will check k-1 and k
//                 if( k-1 >= 0) ans = min( ans,  (vr[i] - vb[j+ind]) * (vr[i] - vb[j+ind]) +  ( vb[j+ind] - vg[k-1]) * ( vb[j+ind] - vg[k-1]) + ( vr[i] - vg[k-1]) *( vr[i] - vg[k-1])   );
//                 if( k < g)    ans = min( ans,  (vr[i] - vb[j+ind]) * (vr[i] - vb[j+ind]) +  ( vb[j+ind] - vg[k]) * ( vb[j+ind] - vg[k]) + ( vr[i] - vg[k]) *( vr[i] - vg[k])   );
//             }
//         }
//     }
//     return ans;
        
// }


// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int r,b,g; cin >> r >> b >> g;
//         vi vr(r); l(i,0,r) cin >> vr[i];
//         vi vb(b); l(i,0,b) cin >> vb[i];
//         vi vg(g); l(i,0,g) cin >> vg[i];

//         srt(vr); srt(vb); srt(vg);
//         int ans = 5e18;
//         ans = fn(vr,vb,vg,ans);
//         cout << ans << " ";
//         ans = fn(vr,vg,vb,ans);
//         cout << ans << " ";

//         ans = fn(vb,vr,vg,ans);
//         ans = fn(vb,vg,vr,ans);

//         ans = fn(vg,vb,vr,ans);
//         ans = fn(vg,vr,vb,ans);
        
        

//         cout << ans << endl;

//     }
//     return 0;
// }