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



vi tim(1e3+1,INT_MAX);
void bfs(){
    tim[1] = 0;
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= i; ){
            int val = i / j;
            int nj = i / val; // all j in [j, nj] have same i/j
            int node = i + val;
            if(node <= 1000){
                tim[node] = min(tim[node], tim[i]+1);
            }
            j = nj + 1;
        }
    }
}



signed main(){
    fastio
    bfs();
    int t;
    cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vi b(n+1); l(i,1,1+n) cin >> b[i];
        vi c(n+1); l(i,1,1+n) cin >> c[i];

        vector< pair<int,int> > step_c(n+1, {0,0});
        l(i,1,n+1){
            step_c[i] = make_pair(tim[b[i]], -c[i]);
        }

        // max step would be lesser than 20
        // so i don't need to make any array of k size  as atmax it would be sum of all step <= 20 * n == 20,000
        srt(step_c);
        vi dp(2e4+1, -1);
        dp[0] = 0;


        for( auto &[steps, c] : step_c){
            c = -c;  // coin store in negative for sorting purpose
            for(int i = dp.size()-1; i>=0; i--){
                if( i - steps >= 0 && dp[i-steps] != -1){
                    dp[i] = max(dp[i],c + dp[i-steps]);
                }
            }
        }

        l(i,1,dp.size()) dp[i] = max(dp[i], dp[i-1]);

        cout << (k > 20000 ? dp[20000] : dp[k]) << endl;
        
    }
    return 0;
}