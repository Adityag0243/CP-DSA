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
    // fastio;
    freopen("inp.txt", "r", stdin);
    freopen("opt.txt", "w", stdout);
    int t;
    cin >> t;
    l(j,1,t+1){
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        int hi = mxv(v);
        int lo = mnv(v);
        int m = hi;
        while( lo <= hi ){
            int mid = (lo + hi)/2;
            vi a(n, 0);
            l(i,0,n) if(v[i] <= mid) a[i] = 1;
        
            l(i,0,n){
                if(a[i] == 0) continue;

                int j = i+1;
                // if(j < n) cout << a[j] << " " << a[i] << ", ";
                while( j < n && a[j] != 1){
                    if( abs(v[j] - v[j-1]) > mid) break;
                    a[j] = 1;
                    j++;
                }
                // for( int x : a) cout << x << " "; cout << endl;
                j = i-1;

                while( j >= 0 && a[j] != 1 ){
                    if( abs(v[j] - v[j+1]) > mid ) break;
                    a[j] = 1;
                    j--;
                }
                // for( int x : a) cout << x << " "; cout << endl << endl;
            }
            // cout << mid << " :: " << mnv(a) << " mid and a\n";
            if( mnv(a) == 0){
                lo = mid+1;
            }else{
                m = mid;
                hi = mid-1;
            }
        }
        cout << "Case #"<<j<<": "<< m << endl;
    }
    return 0;
}