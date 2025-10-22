#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
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

vector<vvi> dp(10, vvi(200001, vi(10)));

void pre(){
    for(int d = 0; d <= 9; d++){
        vi frq(10,0); frq[d] = 1;
        dp[d][0] = frq;
        for(int st = 1; st < 200001; st++){
            vi dpi(10);
            l(j,0,9){
                dpi[j+1] = dp[d][st-1][j];
            }
            dpi[0] += dp[d][st-1][9];
            dpi[1] += dp[d][st-1][9];
            l(j,0,10){
                dp[d][st][j] = dpi[j] % MOD2;
            }
        }
    }
}




signed main(){
    fastio;
    pre();

    int t;
    cin >> t;
    while(t--){
        int n, steps; cin >> n >> steps;
        vi frq(10);
        while(n > 0 ){
            int d = n % 10;
            frq[d]++;
            n /= 10;
        }

        long long ans = 0;
        l(j,0,10){
            if(!frq[j]) continue;

            long long cnt = 0;
            for(int d =0; d < 10; d++){
                cnt += dp[j][steps][d];
                cnt %= MOD2;
            }
            ans += (cnt * frq[j]) % MOD2;
        }
        
        cout << ans % MOD2 << endl;
    }
    return 0;
}