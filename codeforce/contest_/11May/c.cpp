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
//     // fastio;
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         if(n==1){
//             cout << 0 << endl;
//         }else{
//             int r = (n-1)/2;
//             int c = (n-1)/2;

//             int sqs = 2;
//             int val = 1;
//             vvi v(n, vi(n));

//             // bool flag = false;
//             // cout << r << " " <<  c << " r and c \n";
//             while(r < n && c < n && r > -1 && c > -1){

//                 l(i,1,sqs){
//                     if(c+1 >= n) break;
//                     v[r][++c] = val++;
//                 }
        
//                 if(n % 2 == 1 && c+1 == n){
//                     break;
//                 }

//                 l(i,1,sqs){
//                     v[++r][c] = val++;
//                 }

//                 sqs++;

//                 l(i,1,sqs){
//                     if(c-1 < 0) break;
//                     v[r][--c] = val++;
//                 }
//                 if(n % 2 == 0 && c-1 == -1) break;

//                 l(i,1,sqs){
//                     v[--r][c] = val++;
//                 }
//                 sqs++;


//                 // cout << "here  ";

//             }
            

//             l(i,0,n){
//                 l(j,0,n) cout << v[i][j] << " ";
//                 cout << endl;
//             }
            

            
//         }
//     }
//     return 0;
// }