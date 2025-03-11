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



void dfs(int node, const vector<set<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}


int fn(vector<set<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    int conCpt = 0;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            ++conCpt;
            dfs(i, adj, visited); 
        }
    }

    return conCpt;
}

signed main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector< set<int> > adj(n);
        vector<int> don(n); // degree of node

        l(i,0,n-1){
            int a,b;
            cin >> a>>b;
            a--;
            b--;
            don[a]++;
            don[b]++;
            adj[a].insert(b);
        }
        
        vector< pair<int,int> > vp;
        l(i,0,n)
        {
            vp.pb({don[i],i});
        }

        // reverse sorting based on degree 
        sort(vp.rbegin(),vp.rend());


        // ans is either ans will be --> degree1 + degree - 1 ||  degree1 + degree - 2
        // taking maxDegree and searching for next max which is not adjacent 
        //  5 5 5 5 5 4 4    either 5,5 is going to give max component whether adjacent or not.

        int minus  = ((adj[vp[0].second].find(vp[1].second) != adj[vp[0].second].end()) || (adj[vp[1].second].find(vp[0].second) != adj[vp[1].second].end())) ? 2 : 1;

        int ans = vp[0].first + vp[1].first - minus;
        if(minus == 2){
            int i = 2;
            while(i<n && vp[i].first == vp[1].first ){

                minus  = ((adj[vp[0].second].find(vp[i].second) != adj[vp[0].second].end()) || (adj[vp[i].second].find(vp[0].second) != adj[vp[i].second].end())) ? 2 : 1;
                ans = max( ans ,  vp[0].first + vp[i].first - minus);
                i++;
            }
        }

        cout << ans << endl;

       

    }
}