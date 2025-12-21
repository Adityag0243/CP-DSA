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
        int n,q; cin >> n >> q;
        vi v(n+1); l(i,1,1+n) cin >> v[i];
        vi c0(n+1); l(i,1,n+1) if(v[i] == 0) c0[i] = 1;
        l(i,1,n+1) c0[i] += c0[i-1];

        vi c1(n+1); l(i,1,n+1) if(v[i] == 1) c1[i] = 1;
        l(i,1,n+1) c1[i] += c1[i-1];



        vi aaspas;
        l(i,1,n) if(v[i] == v[i+1]) aaspas.pb(i);

        // for( int x : aaspas) cout << x << ' ';
        // cout << endl;

        while(q--){
            int l,r; cin >> l >> r;
            // cout << c0[r] - c0[l-1] <<" zero c\n";
            // cout << c1[r] - c1[l-1] <<" zero c\n\n";
            if( (r-l+1 ) % 3 != 0 || (c0[r] - c0[l-1]) % 3 != 0 || (c1[r] - c1[l-1]) % 3 != 0){
                cout << -1 << endl;
            }else{
                int llb = lower_bound(all(aaspas), l) - aaspas.begin();
                if( llb == aaspas.size() || aaspas[llb] >= r){
                    cout << (r-l+1)/3 + 1 << endl;
                }else{
                    cout << (r-l+1)/3 << endl;
                }
            }
        }


    }
    return 0;
}