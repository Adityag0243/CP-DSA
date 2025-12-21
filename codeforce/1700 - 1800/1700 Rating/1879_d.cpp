#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
#define MOD             998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
   
    int n;
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];
    
    vi preXor(n);

    preXor[0] = v[0];
    l(i,1,n) preXor[i] = preXor[i-1]^v[i];

    vi pre_preXor_sum(n);
    pre_preXor_sum[0] = preXor[0];

    l(i,1,n) pre_preXor_sum[i] = (preXor[i] + pre_preXor_sum[i-1])%MOD;

    int ans = 0;

    l(i,0,n){
        ans =  ans + (  (pre_preXor_sum[n-1] * (i+1)) % MOD  -  (pre_preXor_sum[n-1-i] * (i+1))%MOD );
        ans %= MOD;
    }
    
    cout<<ans<<endl;
}