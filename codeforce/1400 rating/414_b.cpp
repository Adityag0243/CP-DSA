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

int dp[2005][2005];

signed main(){
    int n,k;
    cin>>n>>k;

    for(int i = 1 ; i<= 2001 ; i++){
        for(int j = 0 ; j<= 2001 ; j++){
            dp[i][j]= i==1 ? 1 : 0 ;
        }
    }

    for(int i = 1 ; i<= 2001 ; i++){    // length
        for(int j = 1 ; j<= 2001 ; j++){       
            for(int k = j ; k<= 2001 ; k+=j){  // iterate over each multiple and adding value to length+1
                dp[i+1][k] += dp[i][j];
                dp[i+1][k] %= MOD2;
            }
        }
    }

    int sum = 0;
    l(i,1,n+1) sum = (sum + dp[k][i])%MOD2;      // if n is 5 then it comes from multiple of n
    cout<<sum;                                  // as well as by n==4 n==3 n==2 n==1 so adding up them too
    
}