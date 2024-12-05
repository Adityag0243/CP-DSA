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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(12);

        v[0] = 257866589;
        v[1] =246883568 ;
        v[2] =104396128 ;
        v[3] =993389754 ;
        v[4] = 896419206 ;
        v[5] =405836977 ;
        v[6] =50415634;
        v[7] =152940828 ;
        v[8] =847270779 ;
        v[9] =850467106 ;
        v[10] =922287488 ;
        v[11] =622484596;
        srt(v);

        l(i,0,12) cout<<v[i]<<" ";

        cout<<50415634 + 
    }
}