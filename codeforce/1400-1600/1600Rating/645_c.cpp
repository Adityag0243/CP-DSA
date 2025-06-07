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
    string s;
    cin >> s;
    vi v(n);
    l(i,0,n) if(s[i]== '0') v[i]++;
    l(i,1,n) v[i] += v[i-1];

    int ans = 1e6;

    l(i,0,n){
        if( s[i] == '1' || v[i] == 0) continue;

        int lo = k/2;
        int hi = ans;

        while( lo <= hi )
        {
            int mid = (lo + hi) / 2;

            // check work.....
            int ind1 = max( 0ll, i - mid );
            int ind2 = min( n-1, i + mid );
            int rooms;
            if(ind1 == 0) rooms = v[ind2];
            else rooms = v[ind2] - v[ind1 - 1];

            if(rooms >= k+1){
                ans = min(ans, mid);
                hi = mid - 1;
            }else lo = mid + 1;
        }
    }

    cout << ans ;
    return 0;
}