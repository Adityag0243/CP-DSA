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
        int n,m;
        cin >> n >> m;
        vi a(n);
        l(i,0,n) cin >> a[i];

        vi b(m);
        l(i,0,m) cin >> b[i];

        int ans = 2e9;
        int lo = 0;
        int hi = mxv(b);

        while( lo <= hi){
            int mid = (lo+hi)/2;

            int j = m-1;
            bool used = false;
            
            rl(i,0,n)
            {   
                if(j < 0) break;
                if( !used && b[j] <= mid){
                    used = true;
                    j--;
                }else if( b[j] <= a[i]) j--;
            }

            if(j == 0 && !used)
            {   
                ans = min(ans, b[0]);
                j--;
            }

            if(j == -1){
                if(!used){
                    ans = 0;
                    break;
                }else{
                    ans = min(ans, mid);
                    hi = mid-1;
                }
            }else{
                lo = mid+1;
            }
        }

        if(ans == 2e9) cout << -1 << endl;
        else cout << ans << endl;

    }
    return 0;
}