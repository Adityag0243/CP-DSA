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


vi power(300005);
void pre(){
    power[0] = 1;
    l(i,1,300005){
        power[i] = (2* power[i-1])%MOD2;
    }
}

signed main(){
    
    int n; cin >> n;
    vi v(n); l(i,0,n) cin >> v[i];
    pre();
    srt(v);
    int b = n-2;
    int sz = n;

    int ans = 0;
    // addition term...
    for(int i = n-1; i >= 0; i--){
        ans = (ans + (v[i]*(power[b+1]-1))%MOD2 ) % MOD2;
        b--;
    }
    // cout << ans << " ";
    b = n-2;
    for(int i = 0; i<n;i++){
        ans = (ans - (v[i] *  (power[b+1] -1)) + MOD2 )%MOD2;
        b--;
    }
    cout << ans;

    return 0;
}