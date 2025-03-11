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

    while(t--){
        int n;
        cin >> n;
        vi v(125255, 0); // 500*501/2 = 125250


        v[0] = 1;
        l(i,1,n+1){
            rl(j,1,v.size()){
                if( j - i >= 0){
                    v[j] += v[j-i];
                    v[j] %= MOD2;
                }
            }
        }

        if( (n*(n+1)) % 4 != 0 ) cout<<0;
        else{
            int modInverseOf2 = (MOD2 + 1) / 2;
            cout << (v[n*(n+1)/4] * modInverseOf2) % MOD2 << endl;
        }
    }
}