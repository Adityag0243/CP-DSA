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
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        srt(v);
        if((v[0] + v[n-1])   & 1){
            int cnt1 = 0;
            rl(i,0,n){
                if( (v[0] + v[i]) % 2 == 0){
                    cnt1 = n - i - 1;
                    break;
                }
            }
            l(i,0,n){
                if( (v[i] + v[n-1]) % 2 == 0){
                    cnt1 = min(cnt1,i);
                    break;
                }
            }
            cout << cnt1 << endl;

        }else{
            cout << 0 << endl;
        }
    }
    return 0;
}