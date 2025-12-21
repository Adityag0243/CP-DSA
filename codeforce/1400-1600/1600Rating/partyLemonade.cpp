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
    int n,l; cin >> n >> l;

    vi c(31, 1e18); 
    l(i,0,n) cin >> c[i];

    l(i,1,31){
        c[i] = min( c[i], 2*c[i-1] );
    }  
    rl(i,0,30) c[i] = min(c[i], c[i+1]);

    int ans = 1e18;
    int temp = 0;

    for(int i = 30; i >= 0; i--){
        if( (l >> i) & 1 ){
            temp += c[i];
        }
        else ans = min(ans, temp+c[i]); // this line bcz want to buy at least L liters it can be > L also...
    }
    ans = min(ans, temp);

    cout << ans;

    return 0;
}