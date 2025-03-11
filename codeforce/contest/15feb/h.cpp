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

signed main(){
    int t,t1,t2,k;
    cin >> t >> t1 >> t2 >> k;
    vector<pair<double,int>> ans;
    int cnt = 1;

    while(t--){
        double a, b;
        cin >> a >> b;
        double h1 = (a * t1 * (1 - k / 100.0)) + (b * t2);
        double h2 = (b * t1 * (1 - k / 100.0)) + (a * t2);


        
        ans.pb({ max(h1,h2) , -1*cnt});
        cnt ++;
    
    }
    srt(ans);
    rl(i,0,ans.size()){
        cout << -1*ans[i].second <<" ";
        cout <<fixed<<setprecision(2) << ans[i].first<<endl;
    }
}