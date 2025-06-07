#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define int             long long
#define vi              vector<int>
#define vvi             vector<vi>
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
        int n,k;
        cin >> n >>k;
        vi v(n);
        l(i,0,n) cin >> v[i];
        if(n==1){
            cout<<v[0]<<endl;
            continue;
        }

        int ans = 1e18+1;
        if(k>2){
            ans  = 0;
        }else{
            sort(v.begin(), v.end());
            ans = 1000000000000000000;
            for (int i = 1; i < n; i++) {
                // cout<<ans<<endl;
                ans = min(ans, abs(v[i] - v[i - 1]));
            }

            if(k==2){
                l(i,0,n){
                    l(j,0,n){
                        if(i == j ) continue;
                        int diff = abs(v[i] - v[j]);
                        int ind = lower_bound( all(v) , diff) - v.begin();
                        if(ind != n) ans = min(ans , abs( diff - v[ind]));
                        if(ind != 0) ans = min(ans , abs(diff - v[ind-1]));
                    }
                }
                
            }
        }
        

        cout<<min(ans,v[0])<<endl;

        
    }
}