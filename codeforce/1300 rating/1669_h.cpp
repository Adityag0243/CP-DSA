#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
    fastio
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vi v(n);
        int bits[n][32] = {0};
        
        l(i,0,n){
            cin >> v[i];
            l(j,0,32){
                if((1<<j) & v[i]){
                    bits[i][j] = 1;
                }
            }
        }

        int ans = v[0];
        l(i,1,n) ans &= v[i];

        vi cnt(32,0);
        l(j,0,32){
            int c = 0;
            l(i,0,n){
                if(bits[i][j]) c++;
            }
            cnt[j] = c;
            // cout<<j<<" : "<<cnt[j]<<" ";
        }  
        // cout<<ans<<endl;
        rl(i,0,31){
            if(n-cnt[i] <= k){
                ans |= (1<<i);
                k -= (n-cnt[i]);
            }
        }
        cout<<ans<<endl;
        
    }
}