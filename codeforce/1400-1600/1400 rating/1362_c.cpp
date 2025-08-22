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

void pre(map<int,long long> &mp){
    mp[0] = 1;
    mp[1] = 3;
    long long prev = 1;
    for(int i = 2; i <= 60; i++){
        int temp = prev + mp[i-1];
        mp[i] = i+1+temp;
        prev = temp;
    }
}

signed main(){
    fastio;
    int t;
    cin >> t;
    map<int,long long> mp;
    pre(mp);
    // for(int i = 0; i<=60; i++) cout << mp[i] << " ";
    while(t--){no-
        int n; cin >> n;
        long long ans = 0;
        for(int i = 0; i<=60; i++){
            if( (n >> i) & 1) ans += mp[i];
        }
        cout << ans << endl;
    }
    return 0;
}