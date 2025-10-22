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
        int n,m; cin >> n >> m;
        vi v(n, 0);
        
        l(i,0,m){
            int l,r; cin >> l >> r;
            l--; r--;
            l(i,l,r+1) v[i]++;
        }
        vi ans(n);

        int val = 0;
        if(mxv(v) == m){
            l(i,0,n){
                int maxi = mxv(v);
                l(i,0,n){
                    if( v[i] == maxi){
                        v[i] = -1;
                        ans[i] = val++;
                        break;
                    }
                }
            }
        }
        else{
            int ind = -1;
            l(i,0,n){
                int mini = mnv(v);
                l(i,0,n){
                    if( v[i] == mini){
                        v[i] = m+1;
                        ans[i] = val++;
                        break;
                    }
                }
            }
             
        }

        for(int x : ans) cout << x << " ";
        cout << endl;

    }
    return 0;
}