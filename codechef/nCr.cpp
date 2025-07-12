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



int power(int a, int n){
    if(n == 0) return 1;
    if(n == 1) return a;
    int val = power(a,n/2);
    if(n & 1) return (val * val)%MOD2 * a %MOD2;
    return (1ll* val * val ) % MOD2;
}

int nCr(int n, int r){
    int result = 1;
    for(int i = 1; i<= r; i++){
        result = (result * (n- r + i)) % MOD2;
        result = (result *  power(i,MOD2-2)) % MOD2;
    }
    return (result % MOD2);
}


signed main(){
    int n,a,b;
    cin >> n >> a >> b;
    
    cout << (  (power(2,n)-1+MOD2) % MOD2   -   (nCr(n,a)+MOD2)%MOD2 - (nCr(n,b)+MOD2)%MOD2 + 3ll*MOD2) % MOD2 << endl;
    // cout << power(2,n) << endl;
    // cout << nCr(n,a) << endl;
    // cout << nCr(n,b);

    return 0;
}