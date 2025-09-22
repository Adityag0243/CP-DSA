#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n,m;
vi a;
vvi dp(100005, vi (101, -1));

int fn(int i, int prev, vvi &dp){

    if( i == n) return 1;
    if( a[i] != 0 ){
        if( i-1 >= 0 && abs( a[i] - prev) > 1) return 0;
        return fn(i+1, a[i]);
    }
    int op1 = 0;
    if(prev > 1) op1 = fn( i+1, prev-1 );

    int op2 = 0;
    if(prev < m) op2 = fn( i+1, prev+1 );

    int op3 = fn( i+1, prev );

    return (op1+op2+op3)% MOD2;
}

signed main(){
    cin >> n >> m;
    a.resize(n);
    l(i,0,n) cin >> a[i]; 

    if( a[0] == 0){
        int ans = 0;
        l(i,1,m+1){
            ans += fn(1,i);
            ans %= MOD2;
        }
        cout << ans;
    }
    else cout << fn(1, a[0]);
    return 0;
}