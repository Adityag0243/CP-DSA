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


bool customCompare(const std::string &a, const std::string &b) {
    string s1 = a + b;
    string s2 = b + a; 
    if( s1 < s2 ) return true;
    else   return false;
}



signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<string> v(n); 
        l(i,0,n) cin >> v[i];
        sort(v.begin(), v.end(), customCompare);
        // aab
        // aaba
        // --> here   2nd 1st will be better than 1st 2nd

        for (const string &s : v) {
            cout << s;
        }
        cout << endl;

    }
    return 0;
}