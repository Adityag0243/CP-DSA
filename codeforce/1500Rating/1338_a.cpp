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
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    fastio
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n);

        // 10 , 9 , 7 , 13 , 10 , 12, 5 , 9
        // 5    5   5   5    5    5   9   9    (current_val - low_val(from my position till end)) is max diff... )

        l(i,0,n) cin >> v[i];
        int diff = 0;
        int mini = v[n-1];
        rl(i,0,n){
            mini = min(mini,v[i]);    // may be this should not work let seeeeee
            diff = max(diff,v[i]-mini);
            
        }
        int one = 1;

        if(diff==0){
            cout<<0<<endl;
            continue;
        }
        int ans = 0;
        l(i,1,33){
            ans = i;
            if(diff < ((int)1<<i)) break;
        } 
        cout<<ans<<endl;
        
    }
}