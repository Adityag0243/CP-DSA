#include <bits/stdc++.h>
using namespace std;
#define all(arr) arr.begin(), arr.end()
#define vi vector<int>
#define vvi vector<vi>
#define int uint64_t
#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;
#define p(x) cout << (x) << endl;
#define sp(x) cout << (x) << " ";
#define endl '\n'
#define mxv(arr) *max_element(arr.begin(), arr.end())
#define mnv(arr) *min_element(arr.begin(), arr.end())
#define smv(arr) accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr) sort(arr.begin(), arr.end())
#define rev(arr) reverse(all(arr))
#define MOD2 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

int arr[200005]={0};
void solve() {
    int n , m; cin >> n >> m;
    vi a(n); for(int i = 0; i < n; i++) cin >> a[i];
    vi b(m); for(int i = 0; i < m; i++) cin >> b[i];
    for(int i = 0; i < m; i++){
        
        int g = b[i] + a[0];
        if(arr[b[i]] != 0){
                sp(arr[b[i]]);
                continue;
        }
        for(int j = 0; j < n ; j ++){
            g = __gcd(g , b[i] + a[j]);
            if(g==1) break;
        }
        arr[b[i]] = g;
        sp(g);
    }
}
signed main() {
    fastio;
    // int t; cin >> t;
    // while (t--)
        solve();
}