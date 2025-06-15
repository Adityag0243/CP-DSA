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

vvi dp(8,vi (60));
pair<int,int> digits (int n){
    if( n == 0) return {1,0};
    int dig = 0;
    int sum = 0;
    while( n > 0){
        dig++;
        sum += (n % 10);
        n /= 10;
    }
    return {dig,sum};
}


void pre(){
    for(int i = 0; i< 10010010; i++){
        auto pr = digits(i);
        dp[pr.x][pr.y]++;
    }
}


signed main(){
    fastio;
    pre();
    int t;
    cin >> t;
    while(t--){
        
    }
    return 0;
}