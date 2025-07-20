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
        int maxi = (1ll * n * (n+1)) / 2;
        if( m < n || m > maxi) cout << -1 << endl;
        else{
            vi v(n+1);
            l(i,1,n+1){
                v[i] = (i*(i+1))/2;
                v[i] += (n-i)*i;
            }

            int ind = lower_bound(all(v), m) - v.begin();
           
            int root = ind;
            int diff = v[ind]-m;
            cout << root << endl;
            for(int i = 1; i<root; i++) cout << i << " " << root << endl;
            int st = root+1;
            for(int i = 0; i<diff; i++){
                cout << root-1 <<" "<< st << endl;
                st++;
            }
            while( st <= n){
                cout << root << " "<< st << endl;
                st++;
            }
        }
    }
    return 0;
}