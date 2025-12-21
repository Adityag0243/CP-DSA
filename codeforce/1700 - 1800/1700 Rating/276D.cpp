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

int l,r;

int fn(int a, int b, int p){
    if( p == -1){
        if( l <= a && a <= r   && l <= b && b <= r ) return (a^b);
        return 0ll;
    }

    int op1 = a + ( 1ll << p);
    int op2 = b + ( 1ll << p);

    int a1 = 0, a2 = 0;

    if( op1 <= r ){
        a1 = fn( op1, b, p-1);
    }

    if( op2 <= r ){
        a2 = fn( a, op2, p-1);
    }

    if( a1 == 0 && a2 == 0 ){
        return fn(a, b, p-1);
    }

    return max(a1, a2);
}

signed main(){
    cin >> l >> r;
    cout << fn(0ll, 0ll, 61);
    return 0;
}