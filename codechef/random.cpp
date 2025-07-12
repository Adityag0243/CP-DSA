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

int fn(int sum, int n){
    int val1 = ceil((2*sum)/n - n + 1) ;
    int val2 = floor((2*sum)/n - n + 1 );
    if( val2 <= 0  || val1 != val2 || val1 %2 == 1   ) return 0;
    return 1;
}


signed main(){
    fastio;
    int t = 1;
    // cin >> t;
    
    while(t--){
        int N;
        cin >> N;
        int cnt = 0;
        for(int i = 1; i<= 1000100; i++){
            cnt += fn(N,i);
        }
        cout << cnt*2;
      
      
    }
    return 0;
}