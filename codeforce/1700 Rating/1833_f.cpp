#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
using ll = long long;

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

ll power(ll a, ll b, ll mod){
    ll res = 1;
    a = a % mod;
    while(b > 0){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll mod_divide(ll a, ll b, ll mod) {
    a = ((a % mod) + mod) % mod;
    ll inv = power(b, mod - 2, mod);
    return (a * inv) % mod;
}

 
signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,m; cin>>n>>m;
        map<int,int> mp;

        l(i,0,n){
            int a; cin >> a;
            mp[a]++;
        }

        vi vc;
        vector<ll> prefMul;

        for(auto it : mp){
            vc.push_back(it.x);
            prefMul.push_back(it.y);
        }

        n = prefMul.size();
        
        l(i, 1, n) {
            prefMul[i] = (prefMul[i] * prefMul[i - 1]) % MOD2;
        }

        ll ans = 0;
        for(int i = 0; i + m <= n; i++){
            if( vc[i+m-1] != vc[i] + m -1) continue;

            ll cnt = prefMul[i+m-1];
            if(i > 0) cnt = mod_divide(cnt, prefMul[i-1], MOD2);

            ans = (ans + cnt)% MOD2;
        }
        cout << ans << endl;
    }
    return 0;
}