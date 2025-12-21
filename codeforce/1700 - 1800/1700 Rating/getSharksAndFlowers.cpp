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
    int n,p; 
    cin >> n >> p;
    double ans = 0;
    vector<double> pb(n);
    l(i,0,n){
        int l,r; cin >> l >> r;
        double c = r/p - (l-1)/p;
        pb[i] = (c/(r-l+1));
    }

    // l(i,0,n) cout << pb[i] << " ";
    // cout << endl;

    l(i,0,n){
        double nxt = pb[((i+1) % n)];

        //  chosen number has p in itself doesn't matter if next one include or not
        ans += pb[i];

        // chosen number doesn't have p in itself ask nxt to have it 
        ans += (1-pb[i]) * nxt;

        // in above both case system will add up 2000 in itself 1000 to itself 1000 to next one
    }

    cout << fixed << setprecision(10) << ans*2000;
    return 0;
}