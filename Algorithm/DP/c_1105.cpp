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

int n , l , r;
int one , two , zero;
int dp[3][200005];
// int cnt=0;

// int fn(int i , int rem){
//     // cnt++;
//     if(i == n-1){
//         if(rem == 0 ) return zero;
//         if(rem == 1)  return two;
//         if(rem == 2)  return one;
//     }
//     if(dp[rem][i] != -1) return dp[rem][i];

//     return dp[rem][i] = (zero*fn(i+1 , rem)%MOD2 + one*fn(i+1 , (rem+1)%3)%MOD2 + two*fn(i+1,(rem+2)%3)%MOD2 )%MOD2; 
// }




signed main(){
    
    cin >> n >> l >> r;
    zero = r/3 - (l+2)/3 + 1;
    one  = zero , two = zero;
    if(l%3 == 0){
        if(r%3==0){
            one--;
            two--;
        }else if(r%3==1) two--;
    }else if(l%3 == 1){
        if(r%3==1){
            one++;
        }else if(r%3 == 2){
            one++;
            two++;
        }
    }else{
        if(r%3==0){
            one--;
        }else if(r%3 == 2){
            two++;
        }
    }
    // memset(dp, -1, sizeof(dp));

    // cout << fn(0,0) << endl;
    // cout<<cnt<<" ";
    dp[0][0] = zero;
    dp[1][0] = one;
    dp[2][0] = two;
    
    l(i,1,n){
        dp[0][i] = (zero*dp[0][i-1] + two*dp[1][i-1] + one*dp[2][i-1])%MOD2;
        dp[1][i] = (zero*dp[1][i-1] + two*dp[2][i-1] + one*dp[0][i-1])%MOD2;
        dp[2][i] = (zero*dp[2][i-1] + two*dp[0][i-1] + one*dp[1][i-1])%MOD2;
    }
    cout<< dp[0][n-1];
    
}