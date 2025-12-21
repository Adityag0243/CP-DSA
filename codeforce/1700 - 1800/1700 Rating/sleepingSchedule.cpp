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
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n,h,l,r;
vi v(2001);
vvi dp(2001, vi(2001, -1));

signed main(){
    cin >> n >> h >> l >> r;
    int val;

    dp[0][0] = 0;
    for(int i = 1; i <= n ; i++){
        cin >> val;
        for(int j = 0; j<h; j++){

            for(int x = val; x >= val-1 && x >= 0; x--){
                int k = (j-x+h)%h;
                if(dp[i-1][k] != -1){
                    dp[i][j] = max(dp[i][j], dp[i-1][k] + (j >= l && j <= r));
                }
            }
        }
    }

    cout << mxv(dp[n]);


    return 0;
}