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



void printArr( vector<int> &v){
    for(int val : v) cout << val << " ";
    cout << endl;
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,s; cin >> n >> s;
        vi v(n); l(i,0,n) cin >> v[i];

        int sum = smv(v);
       
        if( sum == s) cout << -1 << endl;
        else if( sum > s){
            printArr(v); 
        }else if(s-sum == 1){
           vi freq(3);
           l(i,0,n) freq[v[i]]++;
            // if(freq[1] > 1) cout << -1 << endl;
            // else{
                l(i,0,freq[0]) cout << 0 << " ";
                l(i,0,freq[2]) cout << 2 << " ";
                l(i,0,freq[1]) cout << 1 << " ";
                cout << endl;
            // }
        }else{
            cout << - 1 << endl;
        }

    }
    return 0;
}