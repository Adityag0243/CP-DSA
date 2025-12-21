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

vector<int> spf(10000007);

void pre(){
    l(i,2,10000007) spf[i] = i;
    
    for(int i = 2; i * i < 10000007; i++){
        if(spf[i] == i){
            for(int j = 2*i; j< 10000007; j+= i){
                spf[j] = min(spf[j], i);
            }
        }
    }

}


signed main(){
    pre();
    fastio
    int n,q; cin >> n >> q;
    while( q-- ){
        int d; cin >> d;

        if(d == 1){
            cout << 0 << " " << 1 << endl;
            continue;
        }else if( spf[d] == d){
            cout << 1 << " " << 1 << endl;
            continue;
        }

        int extra = ( (int)sqrt(d) * (int)sqrt(d) == d);

        map<int,int> mp;

        while( d > 1 ){
            mp[spf[d]]++;
            d /= spf[d];
        }


        int len = 0;
        int ans = 1;
        for( auto it : mp){
            len += it.second;
            ans *= (it.second + 1);
        }
        

        cout << len << " " << extra + ans/2 << endl;
    }
    return 0;
}