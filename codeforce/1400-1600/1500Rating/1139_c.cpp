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


int power(int n, int k){
    int val = 1;
    l(i,0,k){
        val = (val * n) % MOD2;
    }
    return val;
}



signed main(){
    int n,k;
    cin >> n >> k;
    vector<vector<pair<int,int>>> adj(n+1);
    l(i,1,n+1){
        adj[i].pb({i,0});
    }
    l(i,1,n){
        int u,v,l;
        cin >> u >> v >> l;
        adj[u].pb({v,l});
        adj[v].pb({u,l});
    }
    // cout << power(25000,75) <<  "      ";
    vector<int> c;
    l(i,1,n+1){
        queue<int> q;
        int cnt = 0;
        if(adj[i][0].first > 0){
            q.push(i);
        }
        
        while( !q.empty() ){
            int u = q.front(); q.pop();
            adj[u][0].first *= (-1);
            cnt++;

            for(int j = 1; j < adj[u].size(); j++){
                int node = adj[u][j].first;
                if(adj[node][0].first > 0 && adj[u][j].second == 0){
                    adj[u][j].first *= (-1);
                    q.push(node);
                }
            }
            // cout << 'y';
        }
        // cout <<  cnt << " ";
        if(cnt > 0) c.push_back(cnt);
    }

    int ans = power(n,k);
    for(auto it : c){
        // cout << ans << endl;
        ans -= power(it,k);
        ans = (ans + MOD2) % MOD2;
    }

    cout << (ans + MOD2) % MOD2;


    return 0;
}