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
    int t;
    cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        vi q(n), r(n);
        for(int &i : q) cin >> i;
        multiset<int> ms;
        for(int x : q) ms.insert(x);

        for(int &i : r) cin >> i;
        srt(q); srt(r);
        int ans = 0;

        rl(i,0,n){
            int y = r[i] + 1; // for remainder r atleat r+1 needed
            //  search for q now such that (x <= q.y + r) <= k  i.e x <= (k-r)/y
            auto it = ms.lower_bound((k-r[i])/y);

           
            if( it != ms.end() && ((*it) * y + r[i] ) <= k ){
                ans++; 
                ms.erase(it);
            }
            else{
                it--;
                if( it != ms.end() && ((*it) * y + r[i] ) <= k ){
                    ans++; 
                    ms.erase(it);
                }
            }
            
            
        }
        cout << ans << endl;
    }
    return 0;
}