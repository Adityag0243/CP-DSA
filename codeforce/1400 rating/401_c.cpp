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
    int t = 1;
    // cin >> t;
    while(t--){
        int n, m ; cin >> n >> m;
        if( n > m+1  || m > 2*n + 2) cout << -1 <<endl;
        else{
            if(n >= m){
                l(i,0,m)
                {
                    cout << "01";
                }
                if(n> m) cout << '0';
                
            }else{
                int pairs = m - (n+1);
                
                l(i,0,pairs){
                    cout << 11;
                    if(n--) cout << '0';
                }
                if(m > 2*pairs){
                    l(i,0,m-2*pairs-1) cout << "10";
                    cout <<1;
                }
            }
            cout << endl;
        }

    }
    return 0;
}