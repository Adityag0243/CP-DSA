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


double power(double a, int b)
{
    double ans = 1;
    l(i,0,b) ans *= a;
    return ans;
}


signed main(){
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    double lc = lcm((int)b,(int)d);
    a *= (lc/b);
    c *= (lc/d);
    b = lc;
    d = lc;

    double p = a/b;  // prob of win for winR
    double q = (1- (c/d)) * (1 - (a/b));  // loss of winR and next_person continuous

    // (W) , (LL W),   (LL LL W),  (LL LL LL W), (LL LL LL LL W), ..... infinitely


    cout << fixed << setprecision(10) << (p / (1-q) ) ;
    return 0;
}