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


#define N 10000007
vector<int> primes(N);

void pre(){
    l(i,0,N) primes[i] = i;
    primes[0] = primes[1] = -1;
    for(int i = 2; i*i < N; i++){
        if(primes[i] == i){
            for(int j = 2*i; j < N; j += i){
                primes[j] = i;
            }
        }
    }
}


signed main(){
    pre();
    fastio;
    int t;
    cin >> t;
    while(t--){
        int a,b; cin >> a >> b;
        if( a > b ) swap(a,b);
        // for(int i = 2; i<= 10; i++) cout << pri
        if( b == a+2 && primes[b] == b && primes[a] == a) cout << "Y\n";
        else cout << "N\n";
        
    }
    return 0;
}