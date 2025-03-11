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
    
        int n,m;
        cin >> n >> m;
        vvi adj(n+1);
 
        l(i,0,m){
                int a,b;
                cin >> a >> b;
                adj[a].pb(b);
                adj[b].pb(a);
        }
 
        vector<bool> done(n+1,false);
        done[1] = true;
        queue<int> q;
        q.push(1);
        vector<int> child_parent(n+1,-1);
 
        while(!q.empty()){
                int node = q.front(); q.pop();
 
                for( auto it : adj[node]){
                        if( !done[it] ){
                                child_parent[it] = node;
                                q.push(it);
                                done[it] = true;
 
                        }
                }
                if(child_parent[n] != -1) break;
        }
        if(child_parent[n] == -1){ 
             cout << "IMPOSSIBLE" ; return 0;
        }



 
        vi ans;
 
        int i = n;
        while( i != -1){
                ans.pb(i);
                i = child_parent[i];
        }
 
        reverse(all(ans));
        cout << ans.size() << endl;
        l(i,0,ans.size()) cout << ans[i] << " ";
 
}