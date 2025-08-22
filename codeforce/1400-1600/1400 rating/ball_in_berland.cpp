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
        int a,b,k; cin >> a >> b >> k;

        vi by(k); l(i,0,k) cin >> by[i];
        vi gl(k); l(i,0,k) cin >> gl[i];

        if( a == 1 || b == 1){
            cout << 0 << endl;
            continue;
        }

        map<int, int> mp1;
        map<int, int> mp2;
        l(i,0,k){
            mp1[by[i]]++;
            mp2[gl[i]]++;
        }

        vi freq1, freq2;
        for( auto it : mp1 ) freq1.pb(it.y);
        for( auto it : mp2 ) freq2.pb(it.y);
        freq1.push_back(0);
        freq1.push_back(0);
        rl(i,0,freq1.size()-1) freq1[i] += freq1[i+1];
        
        

        int ans = 0;
        int i = 1;
        for( auto it : mp1){
            ans += (it.y * freq1[i++]);
        }
        
        
        for(int f : freq2){
            int val = (f * (f-1))/2;
            ans -= val;
        }
        cout << ans << endl;

       
    }
    return 0;
}