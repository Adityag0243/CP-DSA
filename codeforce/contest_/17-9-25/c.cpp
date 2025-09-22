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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi adj[n+1]; 
        vi idg(n+1, 0);

        l(i,0,n-1){
            int u,v,x,y; cin >> u >> v >> x >> y;
            if(x > y){
                adj[u].pb(v);
                idg[v]++;
            }else{
                adj[v].pb(u);
                idg[u]++;
            }
        }
        queue<int> q;
        l(i,1,1+n) if(idg[i] == 0) q.push(i);
        
        vi topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.pb(node);

            for( int child : adj[node]){
                idg[child]--;
                if(idg[child] == 0) q.push(child);
            }
        }
        vi ans(n); 
        int val = n;
        l(i,0,n) ans[topo[i]-1] = val--;

        for(int xc: ans) cout << xc << " "; 
        cout << endl;
        
    }
    return 0;
}