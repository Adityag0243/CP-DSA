#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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

int dp[1003][1003][2];
int n,k;

int m1=0,m2=0,m3=0;

int fn(int cur, int k, int dir){
    m1=max(m1,cur);
    m2=max(m2,k);
    m3=max(m3,dir);

    // base case
    if( k == 1) return 1;
    // if( cur > n || cur < 0) return 1;

    if(dp[cur][k][dir]  != -1) return dp[cur][k][dir]; 


    int c = 0;
    if( dir == 1){

        if(cur < n) c = (fn( cur+1, k, 1) ) % MOD2; 
        else c = 1;

        c %= MOD2;

        if(cur > 1) c += (fn( cur-1, k-1, 0)) % MOD2; 
        else c++;
        
        c %= MOD2;
        dp[cur][k][dir] = c;
    }else{
        
        if(cur > 1) c = (fn( cur-1, k, 0) ) % MOD2; 
        else c = 1;

        c %= MOD2;

        if(cur < n ) c += ( fn( cur+1, k-1, 1)) % MOD2; 
        else c++;

        c %= MOD2;
        dp[cur][k][dir] = c;
    }

    return dp[cur][k][dir];
}



signed main(){
    // fastio;
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;
        memset(dp, -1, sizeof(dp));
        cout << fn(1, k, 1) << endl;
        // cout << m1 << " " << m2 << ' ' << m3 << endl;
    }
    return 0;
}