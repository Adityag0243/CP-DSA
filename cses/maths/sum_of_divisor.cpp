#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
#define MOD             1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

long long n;

// int fnlow(int x){
//     int lo = 1;
//     int hi = 1e12;
//     int ans = 1;
//     while(lo <= hi){
//         int mid = (hi + lo)/2;
//         cout<<"mid:  "<<mid<<" ";
//         if(n/mid >= x){
//             cout<<".. ,";
//             ans = mid;
//             lo = mid+1;
//         }else hi = mid-1;
//     }
//     return ans;    
// }

signed main(){
    cin>>n;
    if(n==1){
        cout<<1;
        return 0;
    }
    int sum = (n%MOD + (((((n - n/2)%MOD) * ((n + n/2+1)%MOD) )%MOD) * 500000004)%MOD)%MOD;
    int i = n/2; 
    int prev = 2;
    // int cnt = 0;
    sum%=MOD;
    // cout<<sum<<"     ";
    while(i >= 2  && prev <= n){
        // cnt++;

        int lo = prev; 
        int hi = n/i;
        prev = hi+1;
        sum  += (((((((i%MOD) * (((hi%MOD - lo%MOD + 1)%MOD)))%MOD * ((lo%MOD + hi%MOD)%MOD))%MOD )%MOD) * 500000004 )%MOD)%MOD;
        i = n/prev;
        // if(cnt%100000 == 0) cout<<sum<<"   ";
    }

    cout<<sum%MOD;
}