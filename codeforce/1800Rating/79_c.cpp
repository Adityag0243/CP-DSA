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

// map<int, int> mp;

// void fn( int val, string &pref ,string &s, string &sc){
//     string org = pref + "#" + sc;
//     int n = org.size();
//     vi lps(n);

//     for(int i = 1; i<n; i++){
//         int j = lps[i-1];
//         while( j > 0 && org[i] != org[j]){
//             j = lps[j-1];
//         }
//         if( org[i] == org[j] ) j++;
//         lps[i] = j;
//     }
//     // cout << org << ": ";
//     // for( int x : lps ) cout << x ;
//     // endl;
//     int m = pref.size();
//     l(i,0,n){

//         if( lps[i] == m){
//             int ind = i - m - 1;
//             s[ind] = '#';
//             if( mp.find(ind) == mp.end() ) mp[ind] = ind+2-m;
//             else mp[ind] = max( mp[ind], ind+2-m); 
//         }

//     }
// }

// signed main(){
//     string s; cin >> s;
//     int n; cin >> n;
//     vector< string > vs(n);  l(i,0,n) cin >> vs[i];
//     string sc = s;

//     for(int i = 0; i<n; i++){
//         fn(i,vs[i], s, sc);
//         cout << s << endl;
//     }


//     pair<int,int> ans = {0,0};
    
//     int p = 0;
//     n = s.size();
//     int i = 0;
//     while( i < n && p < n){
//         while( i < n && s[i] != '#') i++;
        
//         if(ans.x < i - p){
//             ans.x = i-p;
//             ans.y = p;
//         }
//         // assign new ptr which is start char + 1 of current i
//         p = max(p,mp[i]);
//         i++;
//         cout << i << ": " << p << " , ";
//     }
//     cout << ans.x << " " << ans.y << endl;
//     return 0;
// }