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
    int n,m;
    cin >> n >> m;

    vi c(n);
    l(i,0,n) cin >> c[i];
    srt(c);

    vi t(m);
    l(i,0,m) cin >> t[i];

    int lo = 0;
    int hi = 1e10;

    int ans = 0;

    while( lo <= hi ){
        int r = (lo+hi)/2;

        vi vc(n+1,0);
        l(i,0,m){
            int ind = lower_bound( all(c) , t[i]-r) - c.begin();

            if(ind <= 0) vc[0]++;
            else if(ind < n) vc[ind]++;

            ind = upper_bound( all(c) , t[i]+r) - c.begin();
            if(ind < n) vc[ind]--;
        }
        l(i,1,n+1) vc[i] += vc[i-1];

        if( *min_element(vc.begin(), vc.end()-1) <= 0){
            lo = r+1;
        }else{
            ans = r;
            hi = r-1;
        }
    }
    cout << ans << endl;

    return 0;
}