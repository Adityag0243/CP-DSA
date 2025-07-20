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

vi primes;
void pre(){
    vi v(200005, 1);
    
    for(int i = 2; i*i <200005 ; i++){
        if(v[i]){
            for(int j = i*i ; j < 200005; j += i){
                v[j] = 0;
            }
        }
    }

    l(i,2,200005) if(v[i]) primes.pb(i);
}



signed main(){
    pre();
    int n;
    cin >> n;
    vi v(n); l(i,0,n) cin >> v[i];

    int g = 1;
    // l(i,0,n) g = gcd(g, v[i]);
    // l(i,0,n) v[i] /= g;

    // till now atleast gc is my answer it can be more than that
    // if I can get x as factor from n-1 element that is useful for me 
    // as always lcm will be combination of two element then we will get x from any possible pair's lcm
    
    // cout << primes.size() << " prime size\n";
    int psz = primes.size();
    for(int k = 0; k < psz ; k++){
        int x = primes[k];

        int cnt = 0;
        l(i,0,n){
            if(v[i] % x != 0) cnt++;
            else v[i] /= x;
            if( cnt >= 2) break;
        }
        if( cnt < 2){
            g *= x;  // we got one more factor x
            k--;
        }

    }

    cout << g ;

    return 0;
}