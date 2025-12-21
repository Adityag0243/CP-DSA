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

int power(int b, int p){
    if( p == 0) return 1;
    int val = power(b,p/2);
    val = (val * val) % MOD2;
    if(p&1) return (val * b) % MOD2;
    return val;
}

int invMod(int p, int q){
    int gc = gcd(p,q);
    p /= gc;
    q /= gc;
    return (p * power(q, MOD2-2)) % MOD2;
}



signed main(){
    int n,q; cin >> n >> q;
    vi a(q);
    l(i,0,q) cin >> a[i];

    vi v = a;
    l(i,0,q) v[i] = invMod(v[i], power(2,i+1));

    // suffix.....
    rl(i,0,q-1){
        v[i] += v[i+1];
        v[i] %= MOD2;
    }

    vi ans(n+1,0);
    ans[1] =  v[0];

    l(i,0,q-1){
        ans[a[i]] += (v[i+1] * power(2,i));
        ans[a[i]] %= MOD2;
    }
    l(i,1,n+1) cout << ans[i] << endl;
    
    return 0;
}