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

int solve( char c, int a, string &s){
    int pos = 0;
    int sum_ = 0;
    vi as; 
    int n = s.size();
    l(i,0,n){
        if(s[i] == c){
            as.pb(i);
            sum_ += (i - pos);
            pos++;
        }
    }

    int mid = 0;
    int ans = 0;

    for(int i = 0; i<a/2; i++){
        mid++;
        ans += (as[a/2] - as[i]);
    }
    ans -= (mid * (mid+1))/2;

    mid = 0;
    for(int i = 1+a/2; i <a; i++){
        mid++;
        ans += (as[i] - as[a/2]);
    }
    ans -= (mid * (mid+1))/2;


    return ans;

}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int a = 0, b = 0;
        string s; cin >> s;
        l(i,0,n) if(s[i] == 'a') a++; else b++;

        if( a <= 1 || b <= 1){
            cout << 0 << endl;
            continue;
        }

        cout << min(solve('a',a,s), solve('b',b,s)) << endl;
        

    }
    return 0;
}