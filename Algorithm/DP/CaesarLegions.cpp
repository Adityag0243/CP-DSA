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

int n1,n2,k1,k2;
int dp[101][101][101][2];

int fn(int i , int cnt0 , int cnt , int x){
    if(i == n1+n2) return 1;
    if(dp[cnt0][cnt][i][x] != -1){
        return dp[cnt0][cnt][i][x];
    }

    int sum = 0;
    if(x==0){
        if(cnt0 < n1 && cnt < k1)       sum = (sum + fn(i+1 , cnt0+1 , cnt+1 , 0))%100000000;
        if( i - cnt0 < n2 )             sum = (sum + fn(i+1 , cnt0 , 1 , 1))%100000000;
    }else{
        if(cnt0 < n1)                   sum = (sum + fn(i+1 , cnt0+1 , 1 , 0))%100000000;
        if( i-cnt0 < n2 && cnt < k2)    sum = (sum + fn(i+1 , cnt0 , cnt+1 , 1))%100000000;
    }
    return dp[cnt0][cnt][i][x] = sum%100000000;
}

signed main(){
    cin >> n1 >> n2 >>k1 >>k2;
    memset(dp, -1, sizeof(dp));
    
    int ans =fn(1,0,1,1)%100000000;
    ans+= fn(1,1,1,0)%100000000;
    cout << ans%100000000 << endl;
}
