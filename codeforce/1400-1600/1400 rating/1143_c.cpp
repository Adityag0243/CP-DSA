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

    // anyone having c= 1 && zero respect from all their children is going to be deleted...
    int n;
    cin >> n;
    vi c(n+1);     
    vi adj[n+1];  // store all the children 

    l(i,1,n+1){
        int a,b; cin >> a >> b;
        if(a != -1) adj[a].pb(i);
        c[i] = b;
    }

    vi ans;

    l(i,1,n+1){
        if( c[i] == 1 ){
            bool flag = true;
            for( auto child : adj[i]){
                if( c[child] == 0) flag = false;
            }

            if(flag) ans.pb(i);
        }
    }

    if(ans.size() != 0)for( int x : ans) cout << x << " ";
    else cout << -1 ;
    cout << endl;
    return 0;
}