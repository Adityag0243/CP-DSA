#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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
#define MOD2            998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    fastio
    int q,k;
    cin>>q>>k;
    vector<int> dp(k+1,0);
    dp[0] = 1;

    while(q--){
        char sign;
        cin>>sign;
        int a;
        cin>>a;

        if(sign == '+'){

            rl(i,0,k+1){
                if(i-a >= 0){
                    dp[i] += dp[i-a];
                    dp[i] %= MOD2;
                }
            }

        }else{
            l(i,a,k+1){
                dp[i] -= dp[i-a];
                dp[i] %= MOD2;
            }
        }

        cout<<dp[k]<<endl;
    }


}



// if I am at i = 10 then It doesn't matter in what order any coin comes,
// only thing matter is that what are the coin we have at the end of the ith operation and then find 
// how manys to make K that's why that else part works

