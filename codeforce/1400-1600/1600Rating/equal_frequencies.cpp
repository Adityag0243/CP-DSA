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
//         string s; cin >> s;
//         vi f(26);
//         for(char &c : s) f[c-'a']++; 
        

//         int cnt = n-1;
//         string ans = s;


//         for(int i = 1; i<= n; i++){
//             vector<pair<int, char>> vp;
//             set<int> non_occuring_char;
//             l(i,0,26){
//                 if(f[i] == 0) non_occuring_char.insert(char('a' + i));
//                 else{
//                     vp.pb({f[i],char('a' + i) });
//                 }
//             }

//             if( n % i == 0){
//                 int best = i;
//                 sort(vp.begin(), vp.end(), [&](auto &p1, auto &p2) {
//                     return abs(p1.x - best) > abs(p2.x - best);
//                 });

//                 int p1 = 0, p2 = vp.size()-1;
//                 map<char, int> mp;
//                 cout << "doing this... ";
//                 for( auto it : vp ) cout << it.x << " " << it.y << ", ";
//                 cout << endl;

//                 while( p1 < p2){
//                     if(vp[p2].x == best){
//                         mp[vp[p2].y] = best;
//                         p2--;
//                     }else if( vp[p2].x + vp[p1].x == best ){
//                         mp[vp[p2].y] = best;
//                         mp.erase(vp[p1].y);
//                         p1++, p2--;
//                     }else if( vp[p2].x + vp[p1].x > best ){
//                         mp[vp[p2].y] = best;
//                         vp[p1].x -= (best - vp[p2].x);
//                         p2--;
//                     }else{
//                         vp[p2].x += vp[p1].x;
//                         mp.erase(vp[p1].y);
//                         p1++;
//                     }
//                 }

//                 cout << best << " : best value\n";

//                 for( auto it: mp) cout << it.x << " " << it.y << ", ";
//                 cout << endl;

//                 if( vp[p1].x > best){
//                     mp[vp[p1].y] = best;
//                     auto c = non_occuring_char.begin();
//                     while( vp[p1].x > best){
//                         vp[p1].x -= best;
//                         mp[(*c)] = best;
//                         c++;
//                     }
//                 }

//                 for( auto it: mp) cout << it.x << " " << it.y << ", ";
//                 cout << endl;

//                 string si = s;
//                 for(int i = 0; i<n; i++){
//                     if( mp.find(si[i]) != mp.end()  && (mp[si[i]] > 0)  ){
//                         mp[si[i]]--;
//                         if(mp[s[i]] ==0) mp.erase(s[i]);
//                     }
//                 }
//                 for( auto it: mp) cout << it.x << " " << it.y << ", ";
//                 cout << endl;

//                 string useIt = "";
//                 for(auto it : mp){
//                     if( it.y != 0){
//                         for(int i = 0; i<it.y; i++) useIt += it.x;
//                     }
//                 }
//                 cout << useIt << " ";

//                 int pt =0;
//                 int cnti = 0;

//                 for(int i = 0; i<n; i++){
//                     if(mp.find(si[i]) == mp.end()){
//                         cout << "here " << s[i] << ", ";
//                         if (pt < useIt.size()) {
//                             cout <<"then here ";
//                             cnti++;
//                             si[i] = useIt[pt++];
//                         }

//                     }
//                 }
//                 cout << endl;
//                 cout << cnt << " " << cnti <<  " change for bestF " << best  <<  si <<endl ;
//                 if(cnti < cnt){
//                     cnt = cnti;
//                     ans = si;
//                 }

//             }
        
//         }

//         cout << ans << endl;

//     }

//     return 0;
// }