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


long long fact(int n){
    long long ans = 1;
    l(i,1,1+n){
        ans = (ans * i)%MOD2;
    }
    return ans;
}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        int and_ = v[0];
        l(i,0,n) and_ = (and_ & v[i]);
        // cout << and_ << " ";
        
        int cnt = 0;
        l(i,0,n) cnt += (v[i] == and_);
        
        long long ans = (cnt * (cnt-1))  MOD2;

        // fixing two values first and last == and_
        // remaining can be arranged in (n-2)! ways
        cout << (1ll * ans * fact(n-2) ) % MOD2 << endl;
    }
    return 0;
}