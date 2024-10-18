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
int n , W;  
int dp[100005];

signed main(){
    cin >> n >> W;
    int weight , value;
    l(i,0,100005) dp[i]=10000000000;
    // dp[i] - min weight we can get for value i 
    dp[0] = 0;   // Iguess very Important line if it works well 

    l(i,0,n){
        cin >> weight;
        cin >> value;
        rl(j ,0, 100002-value){
            if( dp[j] > W   ||   dp[j] + weight > W ) continue;
            dp[j + value] = min( dp[j + value] ,  dp[j] + weight);
        } 
    }


    

    rl(i,0,100005){
        if(dp[i] <= W){
            cout<<i<<endl;
            break;
        }
    }
}


