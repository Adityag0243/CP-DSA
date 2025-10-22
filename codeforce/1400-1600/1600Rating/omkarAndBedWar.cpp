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


// int dp[200005][2][2]; 
// map<char,int> mp;

// int fn(string &s, char  prevprev, char prev, int i, char f, char s_){

//     if( i == s.size()){
//         if(prev == 'L' && prevprev == 'R'){
//             if(f == 'R' && s_ == 'R') return 200005;
//             return 0;
//         }
//         if(prev == 'R' && prevprev == 'L'){
//             if(f == 'L' && s_ == 'L') return 200005;
//             return 0;
//         }
//         if(prev == 'L' && prevprev == 'L') return ((f == 'L') ? 200005 : 0 );
//         if(prev == 'R' && prevprev == 'R') return ((f == 'R') ? 200005 : 0 );
//     }
//     auto tp = make_tuple(prevprev,prev,f);
//     if(dp[i][mp[prevprev]][mp[prev]] != -1) return dp[i][mp[prevprev]][mp[prev]];

//     int op1 = 200005,op2 = 200005; 
//     if(prevprev == 'L' && prev == 'L'){
//         op1 =  (s[i] != 'R') + fn(s, 'L', 'R', i+1, f, s_ );
//     }else if(prevprev == 'R' && prev == 'R'){
//         op1 =  (s[i] != 'L') + fn(s, 'R', 'L', i+1, f, s_ ); 
//     }else if(prevprev == 'L' && prev == 'R'){
//         op1 =  (s[i] != 'L') + fn(s, 'R', 'L', i+1, f, s_ );
//         op2 =  (s[i] != 'R') + fn(s, 'R', 'R', i+1, f, s_ );
//     }else{
//         op1 =  (s[i] != 'L') + fn(s, 'L', 'L', i+1, f, s_ );
//         op2 =  (s[i] != 'R') + fn(s, 'L', 'R', i+1, f, s_ );
//     }

//     return dp[i][mp[prevprev]][mp[prev]] = min(op1, op2);
// }

// signed main(){
//     fastio
//     int t;
//     cin >> t;
//     while(t--){
//         int n; cin >> n;
//         string s; cin >> s;
//         memset(dp, -1, sizeof(dp));
//         int op1 = (s[0] != 'L') + (s[1] != 'L') + fn(s, 'L', 'L', 2, 'L', 'L');
//         int op2 = (s[0] != 'L') + (s[1] != 'R') + fn(s, 'L', 'R', 2, 'L', 'R'); 
//         int op3 = (s[0] != 'R') + (s[1] != 'R') + fn(s, 'R', 'R', 2, 'R', 'R');
//         int op4 = (s[0] != 'R') + (s[1] != 'L') + fn(s, 'R', 'L', 2, 'R', 'L');
        
//         cout << min({op1,op2,op3,op4}) << endl;
//     }
//     return 0;
// }