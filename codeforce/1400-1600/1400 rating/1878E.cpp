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
        vi v(n);
        l(i,0,n) cin >> v[i];

        int pre[n+1][32];

        // prefixing

            l(i,0,n){
                l(j,0,31){
                    if( v[i] & ( 1 << j)) pre[i+1][j] =  pre[i][j] + 1;
                    else pre[i+1][j] = pre[i][j];
                }
            }

        int q;
        cin>>q;
        while(q--){
            int l , k;
            cin >> l >> k;


            if(v[l-1] < k){
                cout << -1 << " ";
                continue; 
            }

            int ans = l;
            int lo = l ; 
            int hi = n;
            
            while( lo <= hi){

                int mid  = (hi + lo)/2;
                int num = 0;
                l(bit,0,31){
                    if( pre[mid][bit] - pre[l-1][bit] == mid - l + 1){
                        num += (1 << bit);
                    }
                }

                if( num >= k){
                    // ans = max(ans,mid);
                    ans = mid;
                    lo  = mid+1;
                }
                else hi = mid-1;
            }
            cout << ans << " ";
            
            
        }
        cout << endl;
    }
}