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
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int fn(int i ){
    int times = 0;
    while(i % 5 == 0){
        times++;
        i /= 5;
    }
    return times;
}
signed main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        vi ans;

        for(int i = 125; i<= n ; i += 125){
            int num = 0;
            int cur = i;
            while( cur > 1)
            {
                cur /= 5;
                num += cur;
            }
            int times = fn(i);
            
            for(int j = 3; j <= times; j++){
                ans.pb(num-(j-2));
            }
        }
        srt(ans);
        cout << ans.size() << endl;
        l(i,0,ans.size()) cout << ans[i] << " \n"[i == ans.size()-1];
        
    }
    return 0;
}