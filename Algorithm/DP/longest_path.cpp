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

vi adj[100005];
vi dist(100005,-1);
int maxi = 0;

void fn(int index , int distance){
    // for( auto neighbour : adj[index]){
    //     if( distance + 1 > dist[neighbour]){
    //         maxi = max( maxi , distance+1);
    //         dist[neighbour] = distance + 1;
    //         fn(neighbour , distance + 1);
    //     }
    // }
    queue<pair<int , int>> q;
    q.push(make_pair(index,0));

    while (!q.empty()) {
        int node = q.front().first; 
        int dt   = q.front().second;
        q.pop();
        // cout<<node;
        if( dist[node] >= dt) continue;
        maxi = max(maxi , dt);
        // cout << " here with dist: ";
        dist[node] = dt;
        // cout << dist[node] << endl;

        for (int neighbor : adj[node]) {
            q.push(make_pair(neighbor,dist[node]+1)); // Push it into the queue
        }
    }

    
}



signed main(){
    int n , m;
    cin >> n >> m;

    l(i,0,m){
        int x , y ;
        cin >> x >> y;
        dist[y] = 0;
        adj[x].pb(y);
    }
    
    l(i,1,n+1){
        if(dist[i] != 0){  // parent element(node) for others
            dist[i] = -2;
            fn(i,-1);
        }
    }

    cout<< maxi <<" ";
}