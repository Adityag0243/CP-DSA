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
        int r,c,a,b;
        cin >> r >> c >> a >> b;
        if(r + c == 2){
            cout << 0 << endl;
            continue;
        }else{
            int rn = -1, cn = -1;
            int ans = INT_MAX;
            if( true ){
                rn = a;
                cn = c;

                int cnt = 1;

                while( rn > 1){
                    rn = (rn+1)/2;
                    cnt++;
                }

                while( cn > 1){
                    cn = (cn+1)/2;
                    cnt++;
                }

                ans = min( ans , cnt);

            }

            if( true){
                rn = r-a+1;
                cn = c;
                int cnt = 1;

                while( rn > 1){
                    rn = (rn+1)/2;
                    cnt++;
                }

                while( cn > 1){
                    cn = (cn+1)/2;
                    cnt++;
                }

                ans = min( ans , cnt);
            }

            if(true ){
                rn = r;
                cn = b;
                int cnt = 1;

                while( rn > 1){
                    rn = (rn+1)/2;
                    cnt++;
                }

                while( cn > 1){
                    cn = (cn+1)/2;
                    cnt++;
                }

                ans = min( ans , cnt);
            }

            if( true){
                rn = r;
                cn = c-b+1;
                int cnt = 1;

                while( rn > 1){
                    rn = (rn+1)/2;
                    cnt++;
                }

                while( cn > 1){
                    cn = (cn+1)/2;
                    cnt++;
                }

                ans = min( ans , cnt);
            }

            
            cout << ans << endl;

        }
       
        
    }
    return 0;
}