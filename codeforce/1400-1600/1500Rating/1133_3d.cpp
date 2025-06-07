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



pair<int,int> fn(int a, int b){
    if( (a > 0 && b < 0 ) ||  (a < 0 && b > 0)){  // one of them is negative
        a = -(abs(a));
        b = abs(b);
    }else if( a < 0 && b < 0){
        a = abs(a);
        b = abs(b);
    }
 
    int gc = gcd( abs(a), abs(b) );
    return { a/gc, b/gc };
    
}
   
signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);l(i,0,n) cin >> a[i];
        vector<int> b(n);l(i,0,n) cin >> b[i];
        map<pair<int,int>,int> mp;
        int ans = 0;
        int extra = 0;

        l(i,0,n){
            
            if( a[i] == 0 && b[i] == 0) extra++;
            else if( a[i] == 0 && b[i] != 0) continue;
            else if( a[i] != 0 && b[i] == 0) mp[{0,0}]++;
            else{
                mp[fn(a[i],b[i])]++;
            }
        }
        
        for( auto it : mp){
            ans = max(ans, it.y);
        }
        cout << ans + extra ;
    }
    return 0;
}