#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define int             int64_t
#define vvi             vector<vi>
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

signed main(){
    int n,x;
    cin>>n>>x;
    vi v(n);
    l(i,0,n) cin>>v[i];
    vector<int> dp(1e6+5,0);
    dp[0] = 1;
    
    l(i,0,n){
        for(int j = 0; j <= x ; j++){
            if( j+v[i] > x) break;
            if(dp[j] > 0) dp[j+v[i]]+=dp[j];
            dp[j+v[i]] %= MOD2;
        }
    }

    cout<<dp[x];
}