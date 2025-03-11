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
    int t = 1;
    // cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);
        l(i,0,n) cin >> v[i];
        int p;
        cin >> p;
        int m = 0;
        l(i,0,n){
            m += v[i];
            m %= p;
        }

        if(m == 0){
            cout << 0;
            continue;
        }



        // i need m

        vi pref(n);
        pref[0] = v[0];
        if(v[0]%p == 0)v[0] = 0;

        l(i,1,n){
            if(v[i] + pref[i-1] % p == 0) pref[i] = 0;
            else pref[i] =  pref[i-1] + v[i];
        }

        vi suf(n);
        suf[n-1] = v[n-1];
        if(v[n-1] % p == 0) suf[n-1] = 0;
        rl(i,0,n-1){
            if(v[i] + suf[i+1] % p == 0) suf[i] = 0;
            else suf[i] =  v[i] + suf[i+1];
        } 

        int prevZero = -1;
        int ans = n;
        l(i,0,n){
            if(pref[i] == m){
                ans = min ( ans , i - prevZero);
            }
            if(pref[i] == 0) prevZero = i;
        }

        cout<< ans ;

    }
}