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
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i = 0; i<n ;i++) cin >> v[i];

        vector<int> b(m);       
        for(int i = 0; i<m ;i++) cin >> b[i];
        srt(b);

        bool flag = true;

        int mini = v[0];
        l(i,0,m) mini = min(mini , b[i] - v[0]);
        v[0] = mini;
        int prev = v[0];

        for(int i= 1; i<n ; i++){
            int ind = lower_bound(all(b), prev + v[i]) - b.begin();
            if(ind < m ){
                if(prev <= min(v[i], b[ind]-v[i])) v[i] = min(v[i],b[ind] - v[i]);
                else v[i] = max(v[i] , b[ind]- v[i]); 
            }
            prev = v[i];
        }
        // for(int i = 0; i<n ;i++) cout << v[i] << " ";
        
        for(int i = 1; i< n ;i++){
            if(v[i] < v[i-1]) flag = false;
        }

        if(flag) cout <<"YES"<<endl;
        else cout << "NO" << endl;
        
    }
    
}