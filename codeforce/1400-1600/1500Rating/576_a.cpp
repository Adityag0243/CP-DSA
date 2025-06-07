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
void pre(){
    vector<bool> v(10000,true);
    for(int i = 2; i<10000; i++){
        if(v[i]){
            for(int j = 2*i; j<10000; j += i){
                v[j] = false;
            }
        }
    }

    for(int i = 2; i<10000; i++){
        if(v[i]) primes.pb(i);
    }
}


signed main(){
    // fastio;
    int t = 1;
    // cin >> t;
    pre();
    while(t--){
        int n;
        cin >> n;
        vector<int> freq(n+1);
        for(int i = 2; i <= n ; i++){
            for(int j = 0; primes[j] <= i ; j++){
                int num = i;
                int cnt = 0;
                while( num > 1 && num % primes[j] == 0 ) {
                    cnt++;
                    num/= primes[j];
                }
                freq[primes[j]] = max( freq[primes[j]], cnt);
            }
        }

        vi ans;

        for(int i = 2; i <= n; i++ ){
            if(freq[i] > 0){
                int cur = i;
                l(j,0,freq[i]){
                    ans.pb(cur);
                    cur *= i;
                }
            }
        }

        cout << ans.size() << endl;
        for( int x : ans) cout << x << " ";


    }
    return 0;
}