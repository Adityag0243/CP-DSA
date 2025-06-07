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
    int t;
    cin >> t;
    while(t--){
        int n,x,y;
        cin >> n >> x >> y;

        int xor_ = 0;
        l(i,0,n){
            int a;
            cin >> a;
            xor_ ^= a;
        }

        // parity ( adding a to d )  ===  parity( doing xor with d )
        // as even no of bit add up gives 0    even no of bits getting up into xor gives 0
        // odd no of getting add up guves 1    odd no of bits getting up into xor gives 1
        // so alice d     and bob d+3    has different parity
        // irrespective of xor and addition   parity with alice and bob's d is going to be different
        // if parity of (sum of all  +  Alice's d ) matches with Y ---> Alice   else BOB
        // or we can say (xor of all +  alice's d)  matches with Y ---> Alice   else BOB
        if( (xor_ + x + y) & 1 ) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
    }

}