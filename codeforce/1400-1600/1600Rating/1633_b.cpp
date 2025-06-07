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


vi tim(1e3+5,INT_MAX);


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
    // fastio;
    int t;
    cin >> t;

    bfs();


    while(t--){
        int n, k;
        cin >> n >> k;
        vi b(n);
        l(i,0,n) cin>> b[i];

        vi c(n);
        l(i,0,n) cin >> c[i];

        vector< pair<int, int> > vp(n);
        l(i,0,n){
            vp[i] = {tim[b[i]],-c[i]};
        }

        
        srt(vp);

        map<int,int> dp;

        dp[0] = 0;
        l(j,0,n){
            for(auto it : dp){
                int i = it.x;
                if( i + vp[j].x <= 0 && dp.find(i+vp[j].x) != dp.end()){
                    dp[i+vp[i].x] =  max(dp[i], dp[i-vp[j].x] - vp[j].y);
                }else{
                    dp[i+vp[i].x] = dp[i-vp[j].x] - vp[j].y;
                }
            }
        }
        int ans = 0;
        for(auto it : dp)
        {
            ans = max(ans, it.y);
        }


    }
    return 0;
}