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
        int n; cin >> n;
        map<int,vector<int>> mp;
        vector<int> v(1 << n);
        
        for(int i = 0; i < (1 << n); i++){
            bool flag = false;
            for( int j = n; j >= 0; j-- ){
                int iwant = ( 1 << j ) - 1;
                if( (i & iwant) == iwant  && v[i] == 0) {
                    v[i] = 1;
                    flag = true;
                    mp[iwant].push_back(i);
                }
            }
            if(!flag) cout << i << ", ";
        }

        for( int j = n; j >= 0; j-- ){
            for( int val : mp[(1 << j) - 1]){
                cout << val << " ";
            }
        }
        cout << endl;
    }
    return 0;
}