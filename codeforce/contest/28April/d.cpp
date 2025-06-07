// wrong......

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


// vi primes;
// void fn() {
//     int n = 5e5+5;
//     vector<bool> is_prime(n + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i <= n; ++i) {
//         if (is_prime[i]) {
//             primes.pb(i);
//             for (int j = i * 2; j <= n; j += i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
// }




// signed main(){
//     fastio;
//     int t;
//     cin >> t;
//     fn();
//     srt(primes);

//     while(t--){
//         int n;
//         cin >> n;

//         vi v(n);
//         l(i,0,n) cin >> v[i];

//         vector<bool> pri(4e5+1,true);

//         l(i,0,n){
//             int pos = lower_bound( all(primes), v[i]) - primes.begin();
//             if( primes[pos] == v[i]){
//                 v[i] = -1;
//                 pri[primes[pos]] = false;
//             }
//         }

//         sort(v.rbegin(), v.rend());
        
//         int i = 0;
        
//         while(i < n && v[i] == -1) i++;

//         int j = 0;
//         int extra = 0;
//         while(i < n && primes[j] <= v[i]){
//             if( !pri[primes[j]]) j++;
//             extra += (v[i] - primes[j]);
//             pri[primes[j]] = false;
//             i++;
//         }
//         while(i < n && extra > 0){
//             if( !pri[primes[j]]) j++;
//             extra -= (primes[j] -= v[i]);
//             if(extra < 0){
//                 i--;
//             }else{
//                 pri[primes[j]] = false;
//             }
//             i++;
//         }
//         if(i >= n) cout << 0 << endl;
//         else{
//             int cnt = 0;
//             int ind = i;
//             l(j,i,n){
//                 int pos = lower_bound( all(primes), v[j]) - primes.begin();
//                 if( pri[primes[pos]] ){
//                     pri[primes[j]] = false;
//                     cnt++;
//                 }
//             }
//             if(pri[v[n-1]]){
//                 cout << n-ind-cnt-1 << endl;
//             }else{
//                 cout << n-ind-cnt << endl;
//             }
//         }


        
//     }
//     return 0;
// }