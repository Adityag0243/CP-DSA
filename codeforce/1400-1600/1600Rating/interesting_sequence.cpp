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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n, x; cin >> n >> x;

        if(n == x){
            cout << x << endl;
        }
        else if( (n & x) != x){
            cout << -1 << endl;
        }
        else if( x == 0){
            rl(i,0,62){
                if( (n >> i) & 1 ){
                    cout << (1ll << (i+1)) << endl;
                    break;
                }
            }
        }else{
            bool flag = false;
            int xor_ = n ^ x;  // extra bits
            // off all the extra bit in n  i.e ==> n ^ (n ^ x)
            // set the first bit > highest bit in xor_    but it must be before x lowest on bit

            l(i,0,62){
                if((x >> i ) & 1) break;

                if( (xor_ >> i) & 1){
                    xor_ ^= (1ll << i);   
                }else if( xor_ == 0){
                    xor_ ^= (1ll << i);
                    flag = true;
                    break;
                }
            }
            if(flag) cout << (n^(n^x)^xor_) << endl;
            else cout << -1 << endl;
    
        }
        
        
        
    }
    return 0;
}

