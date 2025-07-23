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
    // fastio;
    int t;
    cin >> t;
    while(t--){
        int l,r; cin >> l >> r;
        int ans = r-l+1;
        vi v = {2,3,5,7};
        for( int p : v){
            int c2 = r/p;
            int c1 = (l-1)/p;
            ans -= (c2-c1);
        }

        vi v2 = {6,10,14,15,21,35};
        for( int p : v2){
            int c2 = r/p;
            int c1 = (l-1)/p;
            ans += (c2-c1);
        }
        v = {30,42,70,105};
        for( int p : v){
            int c2 = r/p;
            int c1 = (l-1)/p;
            ans -= (c2-c1);
            // cout << (c2-c1) << " ";
        }

        ans += ((r/210 ) - (l-1)/210);
        cout << ans << endl;


    }
    return 0;
}