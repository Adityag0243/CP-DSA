#include <bits/stdc++.h>
using namespace std;
#define ll(i , s , n)        for(int i = s; i < n; i++)
#define rl(i , s , n)        for(int i = s; i < n; i++)
#define all(arr)             arr.begin(), arr.end()
#define vi                   vector<int>
#define pi                   pair<int , int>
#define vvi                  vector<vi>
#define vpi                  vector<pi>
#define int                  int64_t
#define f                    first
#define s                    second
#define pb(x)                push_back(x)
#define ppb()               pop_back()
#define YES                  cout << "YES" << endl;
#define NO                   cout << "NO" << endl;
#define p(x)                 cout << (x) << endl;
#define sp(x)                cout << (x) << " ";
#define endl                 '\n'
#define lb(arr , x)          lower_bound(arr.begin() , arr.end() , x)
#define ub(arr , x)          upper_bound(arr.begin() , arr.end() , x)
#define bn(arr , x)          binary_search(arr.begin() , arr.end() , x)
#define mxv(arr)             *max_element(arr.begin(), arr.end())
#define mnv(arr)             *min_element(arr.begin(), arr.end())
#define smv(arr)             accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)             sort(arr.begin(), arr.end())
#define rsrt(arr)            sort(arr.begin(), arr.end() , greater<int>())
#define rev(arr)             reverse(all(arr))
#define MOD                  1000000007
#define lcm(a , b)           ((a) * (b)) / __gcd((a) , (b))
#define fastio               ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
bool cmp(const std::vector<int>& a, const std::vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];  
    } else if (a[1] != b[1]) {
        return a[1] < b[1];  
    } else {
        return a[2] < b[2];  
    }
}
void solve() {
    vvi v(3 , vi (3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> v[i][j];
        }
    }
    sort(all(v) , cmp);
    bool f1 = false;
    bool f2 = false;
    if(v[0][0] < v[1][0] || v[0][1] < v[1][1] || v[0][2] < v[1][2]) f1 = true;
    if(v[1][0] < v[2][0] || v[1][1] < v[2][1] || v[1][2] < v[2][2]) f2 = true;
    
    if(v[0][0] <= v[1][0] && v[0][1] <= v[1][1] && v[0][2] <= v[1][2] && v[1][0] <= v[2][0] && v[1][1] <= v[2][1] && v[1][2] <= v[2][2] && f1 && f2){
        cout << "yes" << endl;
    } else cout << "no" << endl;

}
signed main() {
    fastio;
    int t; cin >> t;
    while (t--)
        solve();
}