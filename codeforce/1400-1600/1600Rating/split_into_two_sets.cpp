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
        vi frq(n, 0);
        int a,b;
        bool flag = true;
        vi adj[n];

        l(i,0,n){
            cin >> a >> b;
            frq[a-1]++; frq[b-1]++;
            adj[a-1].pb(b-1);
            adj[b-1].pb(a-1);
        }
        if(mnv(frq) != 2 || mxv(frq) != 2) flag = false;
        vi color(n, -1);
        queue<int> q;
        for(int i = 0;  i < n ; i++){
            if(color[i] != -1) continue;
            color[i] = 0;
            q.push(i);
            while(!q.empty()){
                int u = q.front(); q.pop();
                for(int v : adj[u]){
                    if (color[v] == -1) {
                        color[v] = 1 - color[u]; 
                        q.push(v);
                    }
                    else if (color[v] == color[u]) {
                        flag = false; 
                        break;
                    }
                }
            }
        }
        if(flag)   yes 
        else no
    }
    return 0;
}