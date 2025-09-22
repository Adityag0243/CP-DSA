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


// string s; 
// int n,tw;
// vector<int> pcnt(1000005);
// vector<int> pscnt(1000005);

// vector<vector<double>> dp(1000005, vector<double>(2, 0.0));
// vector<vector<double>> sufdp(1000005, vector<double>(2, 0.0));

// double fn(){
//     sufdp[n-1][0] = 0.0;
//     sufdp[n-1][1] = 0.0;
//     // int j = (s[n-1] == 'C') ? 1 : 0;
//     for(int i = n-2; i >= 0; i--){
        
//         for(int j =0; j<2; j++){

//             if( (s[i]=='C' && j == 1) || ( s[i] == 'W' && j == 0)){
//                 dp[i][j] = pscnt[i] + sufdp[i+1][j];
//             }else{
//                 // int cnt = pscnt[i];
//                 int cnt =  pcnt[i]*(n-i) + pscnt[i+1];
//                 cout << i << " : " << cnt << endl;
//                 dp[i][j] =cnt + sufdp[i+1][j];
//             }

//             dp[i][j] /= (n-i);
//             sufdp[i][j] = dp[i][j] + sufdp[i+1][j];
//         }
//     }
//     return (s[0] == 'W') ? dp[0][0] : dp[0][1];
// }



// signed main(){
//     // freopen("foreign.in", "r", stdin);
//     // freopen("foreign.out", "w", stdout);
//     cin >> s;
//     n = s.size();
//     pcnt.resize(n+1);

    
//     l(i,0,n) if(s[i] == 'W') pcnt[i] = 1;
//     rl(i,0,n) pcnt[i] += pcnt[i+1];
//     l(i,0,n) cout << pcnt[i] << " \n"[i==n-1];
 
//     rl(i,0,n) pscnt[i] = pcnt[i] + pscnt[i+1];
//     l(i,0,n) cout << pscnt[i] << " \n"[i==n-1];

    

//     // cout << fixed << setprecision(10) <<fn();
//     fn();
//     cout << "DP\n";
//     l(i,0,n) cout << dp[i][0] << " \n"[i==n-1];
//     l(i,0,n) cout << dp[i][1] << " \n"[i==n-1];


//     return 0;
// }