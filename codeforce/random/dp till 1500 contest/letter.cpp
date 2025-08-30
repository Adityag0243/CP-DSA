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
    string s;
    cin >> s;
    int n = s.size();
    vi v(n+1);
    l(i,0,n) if(s[i] < 'a') v[i]++;
    l(i,1,n+1) v[i] += v[i-1];

    int ans = n;
    if(v[n] == 0 || v[n] == n) ans = 0;

    // all smaller..
    ans = min(ans, v[n]);
    // all larger
    ans = min(ans, n-v[n]);
    l(i,1,n){
        ans = min(ans, (i-v[i-1]) + (v[n] - v[i-1]));
    }
    cout << ans << endl;

    return 0;
}