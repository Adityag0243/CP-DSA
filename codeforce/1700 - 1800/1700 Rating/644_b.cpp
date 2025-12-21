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
    fastio
    int n,b;
    cin >> n >> b;

    queue<pair<int,int>> q;
    int timer = 0;
    int cur_time = 0;
    
    l(i,0,n){
        int t,d; cin >> t >> d;
        cur_time = t;
        
        while( !q.empty() && q.front().x  <= cur_time){
            q.pop();
        }

        if( q.size() < b || ( q.size() == b && q.front().x == t)){
            t = max(t,timer);
            q.push( {t,d} );
            timer = max(t,timer) + d;
            cout << timer << " ";
        }else{
            cout << -1 << " ";
        }
        

        

    }
    cout << endl;
    return 0;
}