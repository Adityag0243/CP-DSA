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
    int t = 1;
    
    while(t--){
        int n , x;
        cin >> n >> x;
        vi v(n+1);
        v[0] = 0;
        l(i,1,n+1) cin >> v[i];
        l(i,1,n+1) v[i] += v[i-1];

        int pt1 = 1;
        int pt2 = 1;

        int cnt = 0;
 
        // v[i] > 0 (it is important if it has zero then  for x = 7 array  0 2 5 0 could be tricky)

        while( pt2 <= n ){
            int curr = v[pt2]-v[pt1-1];
            if( curr > x){
                pt1++;
                if(pt2 < pt1) pt2++;
            }else if(curr == x){
                cnt++;
                pt1++;
            }else{
                pt2++;
            }
        }
        cout<<cnt;

        
    }
}