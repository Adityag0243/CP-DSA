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
        int n,k; cin >> n >> k;

        string s; cin >> s;

        int zero = 0 ,one = 0 ,two = 0;
        l(i,0,k){
            if(s[i] == '0') zero++;
            else if( s[i] == '1') one++;
            else two++;
        }

        int cnt = n - one - two;
        string ans = "";


        if( n == zero + one + two  ){
            l(i,0,n) ans += '-';
            cout << ans << endl;
            continue; 
        }
        l(i,0,n) ans += '+'; 


        l(i,0,zero) ans[i] = '-';
        rl(i,0,one) ans[n-1-i] = '-';


        vi f(n, 0);
        l(i,zero, zero+two){
            ans[i] = '?';
            f[i]++;
        }
        l(i,0,two){
            ans[n-one-1-i] = '?'; 
            f[n-one-1-i]++;
        }

        l(i,zero,zero + 2) if(i < n) f[i]++;
        l(i,0,2) if(n-1-one-i >= 0) f[n-1-one-i]++;
        
        l(i,0,n){
            if(f[i] == 3) ans[i] = '-';
        }


        cout << ans << endl;
    }
    return 0;
}