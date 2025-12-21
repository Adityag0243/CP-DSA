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

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,m; cin >> n >> m;
        vvi v(n, vi (m));
        l(i,0,n) l(j,0,m) cin >> v[i][j];

        vvi pf = v;
        l(i,0,n){
            l(j,1,m) pf[i][j] = max(pf[i][j], pf[i][j-1]); 
        }
        vvi dpf = pf;

        l(i,1,n){
            pf[i][0] = max(pf[i][0], pf[i-1][0]);
            l(j,1,m) pf[i][j] = max({pf[i][j], pf[i-1][j], pf[i][j-1]});
        }
        
        vvi sf = v;
        l(i,0,n){
            rl(j,0,m-1) sf[i][j] = max(sf[i][j], sf[i][j+1]);
        }
        vvi dsf = sf;
        l(i,1,n){
            sf[i][m-1] = max(sf[i][m-1], sf[i-1][m-1]);
            rl(j,0,m-1) sf[i][j] = max({sf[i][j], sf[i][j+1], sf[i-1][j]});
        }

        
        rl(i,0,n-1){
            dpf[i][0] = max(dpf[i][0], dpf[i+1][0]); 
            l(j,1,m){
                dpf[i][j] = max({dpf[i][j], dpf[i+1][j], dpf[i][j-1]});
            }
        }
        
        rl(i,0,n-1){
            dsf[i][m-1] = max(dsf[i][m-1], dsf[i+1][m-1]);
            rl(j,0,m-1){
                dsf[i][j] = max({dsf[i][j], dsf[i][j+1], dsf[i+1][j]});
            }
        }



        int ans = 1e9;
        l(i,1,n-1){
            l(j,1,m-1){
                vi mi = {pf[i-1][j-1], sf[i-1][j+1], dpf[i+1][j-1], dsf[i+1][j+1]};
                srt(mi);
                ans = min(ans, mi[3] - mi[0]);
            }
        }
        cout << ans << endl;
    }
    return 0; 
}