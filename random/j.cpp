// https://codeforces.com/problemset/gymProblem/101628/J
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
    int n,k;
    cin >> n >> k;
    
    vector<tuple<int, int, int>> v(n);
    int lo = 0;
    int hi = 0;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        lo += a;
        hi = max(hi,a);
        v[i] = make_tuple(a, b, c);
    }

    srt(v);

    lo = (lo+n-1)/n;

    int ans = hi;

    while( lo<=hi ){
        int mid = (lo + hi)/2;

        int sum = 0;
        vector<pair<int,int>> lesser;

        int need = 0;
        for(auto &t : v){
            if(get<0>(t) > mid){
                need += get<0>(t) - mid;
                sum += (get<0>(t) - mid) * get<1>(t);
            }
            else lesser.pb({get<2>(t),get<0>(t)});
        }
        srt(lesser);
        l(i,0,lesser.size()){
            if(need <= 0) break;
            int can_get = mid - lesser[i].y;
            int got = min(need,can_get);
            need -= got;
            sum += got * lesser[i].x;
        }


        if( sum <= k){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }        
    }
    cout << ans << endl;


    return 0;
}