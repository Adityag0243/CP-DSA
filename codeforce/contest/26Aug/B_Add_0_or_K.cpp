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

vector<int> primes;
void fn(int n) {
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    l(i,2,1+n) {
        if (isPrime[i]) primes.pb(i);
    }
 
}


signed main(){
    fastio;
    int t;
    cin >> t;
    fn(100005);

    while(t--){
        int n,k; cin >> n >> k;
        vi v(n); l(i,0,n) cin >> v[i];

        if(n == 1){
            cout << v[0] + k << endl;
            continue;
        }else if( k & 1){
            l(i,0,n){
                if(v[i] & 1) v[i] += k;
            }
        }else{
            int num = k+1;
            for( int p : primes){
                if(k % p != 0){
                    num = p;
                    break;
                }
            }

            l(i,0,n){
                if( v[i] % num != 0){
                    while( v[i] % num != 0) v[i] += k;
                }
            }
        }
        for(int val : v) cout << val << " ";
        cout << endl;
    }
    return 0;
}