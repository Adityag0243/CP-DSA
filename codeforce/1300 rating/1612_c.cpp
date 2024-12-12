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
    fastio
    int t;
    cin >> t;
    while(t--){
        int k,x;
        cin >> k >>x;
        int before_k = (k-1)*k/2;
        if( x >= 2*before_k + k) cout<<2*k-1<<endl;
        else{
            int ans = 0;

            if( x > before_k + k){
                x -= (before_k + k);
                // k-1  k-2  k-3 ....  1  --> n*(2*a + (n-1)d )/2  >= x   (d = -1 a=first_term k-1)
                // n *( 2*k - 2 - n + 1)/2
                int lo = 0;
                int hi = k-1;
                while(lo <= hi){
                    int mid = lo + (hi - lo)/2;
                    if( mid * (2*k -1 - mid)/2 >= x ){
                        ans = k + mid;
                        hi = mid-1;
                    }else lo = mid+1;
                }

            }else{
                // ans*(ans+1)/2 is just greater than equal to x
                // ans*ans + ans >= 2*x    min val of ans to satisfy this

                int lo = 0;
                int hi = 1e9;
                int addup = 0;
                while(lo <= hi){
                    int mid = lo + (hi - lo)/2;
                    if( mid*mid + mid >= 2*x){
                        ans = mid;
                        hi = mid-1;
                    }else lo = mid+1;
                }
                
            }
            cout<<ans<<endl;
        }
         
        
    }
}