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
#define mod            998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi v(n+1, 0);
        vector<vector<int>> adj(n+1);

        for(int i = 2; i <= n; i++){
            int a;
            cin >> a;
            adj[a].push_back(i);
            v[a]++;
        }

        int ans = 1;    // zeroth layer done
        ans += v[1];   // first layer done
        
        queue<int> q;
        q.push(1);
        int layer = 0;

        vector< vector<int> > vl;
        
        while(!q.empty()){
            int size = q.size();
            vi vin;
            while(size--){
                int node = q.front();
                q.pop();
                vin.pb(node);
                for(int child : adj[node]){
                    q.push(child);
                }
            }
            vl.pb(vin);
            
            layer++;
        }

        int prevt = 1;
        for(int i = 1; i< vl.size()-1; i++){

            for(auto it : vl[i]){
                
                int c = ( (prevt) *(vl[i+1].size() -  v[it])) %mod;
                ans += c;
                ans %= mod;
            }
            prevt *= (vl[i].size()-1);
        }


        cout << ans << endl;
    }
}