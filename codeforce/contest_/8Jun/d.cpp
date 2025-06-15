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

pair<int,int> fn(int a, int b,int n){
    //  a = x*1 + y*n
    //  b = x*2 + y *(n-1)
    // 2a - b = y*(n+1)
    if( (2*a-b) % (n+1) != 0) return {-1,-1};
    int y = (2*a-b)/(n+1);
    int x = a - y*n;
    return { x,y};
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        if(n == 1){
            yes
        }else{
            bool flag = true;
            auto p = fn(v[0],v[1],n);
            int x = p.x;
            int y = p.y;
            if( x < 0 || y < 0) flag = false;
            l(i,2,n){
                if( v[i] != x*(i+1) + y*(n-i) )flag = false;
            }       
            if(flag) yes
            else no
        }
    }
    return 0;
}