#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define endl            '\n'
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define mod             1000000007
#define f               first
#define s               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
	fastio
	int n,m; cin >> n >> m;
	string s; cin >> s;
		
	vector<string> sp = {"abc", "acb", "bac", "bca", "cab", "cba"};
	vector<vector<int>> pref(6, vector<int>(n+1, 0));
	
	for(int i = 0; i<6; i++){
		for(int j = 0; j < n; j++){
			if( sp[i][j % 3] != s[j] )
				pref[i][j+1] = 1;
		}
	}
	
	for(int i = 0; i<6; i++){
		for(int j = 1; j <= n; j++){
			pref[i][j] += pref[i][j-1];
		}
	}
	
	while(m--){
		int l,r; cin >> l >> r;
		int ans = n;
		for( int i = 0; i < 6; i++){
			ans = min(ans, pref[i][r] - pref[i][l-1]);
		}	
		cout << ans << endl;
	}
	
	
}