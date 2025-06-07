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
    int t = 1;
    // cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        // int turn = false;
        int i = 0;
        int ans = 0;
        while( i < n){
            if( v[i] == 1){
                i++;
            }else{
                bool turn = false;
                if(i == 0) turn = true;
                int cnt = 0;
                while(i<n && v[i] == 0){
                    i++;
                    cnt++;
                }
                if( i == n) turn = true;
                
                if(!turn){
                    ans += 2*cnt;
                    turn = false;
                }
                // else ans += 2*cnt;

            }
        }
        cout << max(ans,1ll) ;
    }
    return 0;
}