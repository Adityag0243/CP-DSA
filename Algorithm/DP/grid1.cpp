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


int h , w;
int dp[1001][1001];
char arr[1001][1001];

bool is_valid(int i , int j){
    if(i==0 || j==0) return true;
    return (i<=h && i>0 && j>0 && j<=w && arr[i][j]=='.');
}

signed main(){
    cin >> h >> w;
    memset(arr, 0, sizeof(arr));
    l(i,1,h+1){
        l(j,1,w+1){
            cin >> arr[i][j];
        }
    }
    memset(dp, 0, sizeof(dp));

    // start logic now............
    l(i,1,h+1){
        l(j,1,w+1){
            if(i ==1 && j ==1) dp[i][j] = 1;
            if( arr[i][j] == '#') continue;
            if( is_valid(i-1,j) ) dp[i][j] += dp[i-1][j];
            if( is_valid(i,j-1) ) dp[i][j] += dp[i][j-1];
            dp[i][j]%=MOD2;
        }
    }
    cout<<dp[h][w];
    
}