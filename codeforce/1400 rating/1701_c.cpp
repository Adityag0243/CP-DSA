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
        int n , m;
        cin >> n >> m;
        vi v(m);
        l(i,0,m) cin >> v[i];
        vi assigned(n,0);
        l(i,0,m) assigned[v[i]-1]++;
        // l(i,0,n) cout<<assigned[i]<<" ";

        int lo = 1;
        int hi = 200005;
        int ans = 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            int cnt = 0;
            l(i,0,n){
                if(assigned[i] >= mid) cnt += mid;
                else{
                    cnt += assigned[i];
                    cnt += (mid - assigned[i])/2;
                }
            }
            if(cnt >= m){
                ans = mid;
                hi = mid-1;
            }else lo = mid+1;
        }
        cout<<ans<<endl;
    }
}