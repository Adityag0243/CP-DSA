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

double power(double a, int b){
	if( b == 0) return 1.0;
	double val = power(a, b/2);
	val *= val;
	if( b & 1) return val * a;
	return val;
}


signed main(){
	int m,n; cin >> m >> n;
	double ans = 0;

	for (int i = 1; i <= m; i += 1)
	{
		ans += i * (double)(power((double)i/m,n) - power((double)(i-1)/m, n)) ;
	}

	cout <<fixed << setprecision(10) <<  ans;
}