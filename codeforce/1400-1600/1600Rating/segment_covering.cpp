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
#define MOD2            998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


vector<pair<  pair<int,int>, pair<int,int>   >> v;

vector<int> dp(200005, -1);
vector<int> wi; // prob / (1-prob)
int n,m;
int ip = 1; // inverse probs   Multiplication of (1 - p/q)'s....

int power(int a, int b){
    if( b == 0) return 1;
    if( b == 1) return a;
    int val = power(a,b/2);
    val = (val * val ) % MOD2;
    if(b & 1) return (val * a) % MOD2;
    return val;
}

int inv_mod(int q){
    return power(q, MOD2-2) % MOD2;
}

int calculate(int p, int q){
    return (p * inv_mod(q))% MOD2;
}



int fn(int pos){
    if(pos > m) return 1ll; 
    if(dp[pos] != -1) return dp[pos];
    
    int ind = lower_bound(all(v), make_pair(make_pair(pos, 0ll), make_pair(0ll, 0ll))) - v.begin();
    

    int ans = 0;

    for(int st = ind; st < n && v[st].x.x == pos; st++){
        int nxt = fn(v[st].x.y+1) % MOD2;
        ans = (ans + wi[st] * nxt % MOD2) % MOD2;
    }
    return dp[pos] = ans;

}

signed main(){
    
    cin >> n >> m;
    v.resize(n);
    wi.resize(n);
    
 
    
    
    l(i,0,n){
        cin >> v[i].x.x >> v[i].x.y >> v[i].y.x >> v[i].y.y;
    }

    srt(v);
    for(int i =0;i<n;i++){
        int p = calculate(v[i].y.x, v[i].y.y);
        ip = (ip * (1 - p + MOD2 )) % MOD2;
        wi[i] = (p * inv_mod(1-p+MOD2))%MOD2;
    }

    
    cout << (ip * fn(1)) % MOD2;

    
    return 0;
}