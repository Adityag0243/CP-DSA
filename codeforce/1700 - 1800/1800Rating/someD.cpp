// // https://codeforces.com/contest/2145/problem/D

// #include <bits/stdc++.h>
// using namespace std;
// #define all(arr)        arr.begin(), arr.end()
// #define int             int64_t
// #define yes             cout << "YES" << endl;
// #define no              cout << "NO" << endl;
// #define endl            '\n'
// #define mxv(arr)        *max_element(arr.begin(), arr.end())
// #define mnv(arr)        *min_element(arr.begin(), arr.end())
// #define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
// #define srt(arr)        sort(arr.begin(), arr.end())
// #define rev(arr)        reverse(all(arr))
// #define mod             1000000007
// #define f               first
// #define s               second
// #define gcd(a,b)        __gcd((a),(b))
// #define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
// #define l(i,st,n)       for(int i=st;i<n;i++)
// #define rl(i,st,n)      for(int i=n-1;i>=st;i--)
// #define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);



// signed main(){
// 	fastio
// 	int t; cin >> t;
// 	while(t--){
// 		int n,k; 
// 		cin >> n >> k;

//         if( k == 0){
//             l(i,1,n+1) cout << i << " \n"[i==n];
//             continue;
//         }else if( k == (n*(n-1))/2){
//             rl(i,1,n+1) cout << i << " \n"[i==1];
//             continue;
//         }


// 		map<int,int> mp;
// 		vector<int> lens;
// 		for(int i = 2; i <=n ; i++){
// 			mp[ i * (i-1)/2] = i;
// 			lens.push_back(i * (i-1) /2);
// 		}
		
// 		int wants = (n *(n-1))/2;
// 		wants -= k;
// 		vector<int> dp(wants + 1, -1);
// 		dp[0] = 0;
// 		mp[0] = 0;
		
// 		for( int x : lens){
// 			for( int i = wants; i > 0 ; i--){
// 				if( i - x >= 0 && dp[i-x] >= 0){
// 					dp[i] = i-x;
// 				}
// 			}
// 		}
//         for(int x : lens) cout << x <<  " ";
//         cout << endl;
// 		for( int x : dp) cout << x << " ";
// 			cout << endl;
		
// 		if( dp[wants] == 0) cout << 0 << endl;
// 		else{
//             int cur = n;
// 			int val = wants;
// 			while( val != 0){
// 				int sz = mp[val-dp[val]];
//                 l(i,0,sz){
//                     cout << cur-- << " ";
//                 }
// 				val = dp[val];
// 			}
//             cout << endl;
// 		}
		
// 	}
// }