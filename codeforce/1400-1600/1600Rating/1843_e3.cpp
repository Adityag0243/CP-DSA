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

        vector<pair<int,int>> seg(m);

        l(i,0,m){
            cin >> seg[i].x >> seg[i].y;
            seg[i].x--;
            seg[i].y--;
        }

        int q; cin >> q;
        vi ind(q); 

        l(i,0,q){
            cin >> ind[i];
            ind[i]--;
        }

        int lo = 1;
        int hi = q;

        int ans = -1;

        while(lo <= hi){
            int mid = (lo+hi)/2;

            vi pref(n);
            l(i,0,mid) pref[ind[i]] = 1;

            l(i,1,n) pref[i] += pref[i-1];

            // cout << mid <<" : ";
            // for(int x: pref) cout << x << " ";
            // cout << endl;


            bool flag = false;
            l(i,0,m){

                int len = seg[i].y - seg[i].x + 1;

                int cnt = pref[seg[i].y];
                if( seg[i].x != 0 ) cnt -= pref[ seg[i].x - 1];
                
                if( cnt >= (len)/2 + 1 ) flag = true;

                if(flag) break;
            }

            if(flag){
                ans = mid;
                hi = mid-1;
            }else{
                lo = mid + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}