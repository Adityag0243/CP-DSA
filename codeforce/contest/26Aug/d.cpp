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
        vector<int> degree(n);
        vector<pair<int,int>> vp(n-1);
        vector<int> adj[n];

       

        l(i,1,n){
            int u,v;
            cin >> u >> v;
            u--; v--;
            vp.pb({u,v});
            adj[u].pb(v);
            adj[v].pb(u);

            degree[u]++;
            degree[v]++;
        }
         if( n == 1 || mxv(degree) < 2){
            cout << -1 << endl;
            continue;
        }
   
        bool flag = true;
        vi ans(3);
        bool ansF = false;
        
        for( auto p : vp){
            int u = p.x;
            int v = p.y;
            if(degree[v] > degree[u]) swap(u,v);

            for( int child : adj[u]){
                if(degree[child] == 1){
                    v = child;
                    break;
                }
            }

            if( degree[u] > 2 && degree[v] == 1 && adj[u].size() > 1){
                
                for(int v2 : adj[u]) 
                    if(v2 != v){
                        if(degree[v2] == degree[u]) continue;
                        if(degree[v2] > degree[u] ) swap(v2, u);
                        
                        if(degree[v2] > 1){
                            flag = false;
                            cout << v2 + 1<< " ";
                            break;
                        }else{
                            ansF = true;
                            ans[0] = v2+1;
                            ans[1] = u+1; 
                            ans[2] = v+1;
                        }
                        
                    }
                if(! flag){
                    cout << u+1 << " " << v+1 << endl;
                    break;
                }
                
            }
        }
        if(ansF && flag) cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        else if( !ansF && flag) cout << -1 << endl;        

    }
    return 0;
}