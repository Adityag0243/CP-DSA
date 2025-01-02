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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        l(i,0,n){
            int a,b;
            cin >> a >> b;
            v[i] = {a,b};
        }
        int lo = 0;
        int hi = 1e9+1;
        int ans = 0;

        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int st  = 0;
            int end = 0; 
            l(i,0,n){
                st  = max(st  - mid, v[i].first);
                end = min(end + mid, v[i].second); 
                if(st > end){
                    st = -1;
                    break;
                }
                if(v[i].first > end || v[i].second < st ){
                    st = -1;
                    break;
                }
            }

            if(st == -1){
                lo = mid + 1;
            }else{
                ans = mid;
                hi  = mid - 1;
            }
        }

        cout<<ans<<endl;
        
    }
}