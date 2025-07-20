// // link cf EDU: https://codeforces.com/edu/course/2/lesson/9/3/practice/contest/307094/problem/G

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
//     long long n,c; cin >> n >> c;

//     string s;
//     cin >> s;
//     vector<long long> preCntA(n) , preABpairs(n);
//     l(i,0,n) if(s[i] == 'a') preCntA[i] = 1;
//     l(i,1,n) preCntA[i] += preCntA[i-1];

//     l(i,0,n) if(s[i] == 'b') preABpairs[i] = preCntA[i];
//     l(i,1,n) preABpairs[i] += preABpairs[i-1];

//     // for (int x : preABpairs) cout << x << " ";
//     // cout << endl;

//     long long ans = 1;
//     // if current preABpairs[i] > c then we need to remove atleast c - preABpairs[i] pairs in total 
//     // so will be BS for this
    
//     // if(preABpairs[n-1] <= c) ans = n;
//     int pt2 = 0;
//     l(i,0,n){
//         if(preABpairs[i] <= c) ans = max(ans, i+1);
//         else{
            
//         }
//     }

//     cout << ans ;


//     return 0;
// }