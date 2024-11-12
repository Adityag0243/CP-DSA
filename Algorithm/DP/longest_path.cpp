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
void fn(int index , int distance);
vi adj[100005];
vi dist(100005,-1);
int maxi = 0;

void fn(int index , int distance){
    // cout<<"fans gaya kya?? ";
    for( auto neighbour : adj[index]){
        // cout << neighbour <<" ";
        if( distance + 1 > dist[neighbour]){
            maxi = max( maxi , distance+1);
            // cout << "here with dist: ";
            dist[neighbour] = distance + 1;
            // cout<< dist[neighbour]<<",  ";
            fn(neighbour , distance + 1);
        }
    }
    
}

vector<int> topo;
bool visited[100005] = {false};

void fntopo(int source){
    visited[source] = true;
    queue<int> q;
    q.push(source);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto node : adj[curr])
        {
            if(visited[node] == false){
                q.push(node);
                visited[node] = true;
            }
        }
        topo.push_back(curr);
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
    for(int i = 1 ; i<n+1 ; i++){
        if(!visited[i]) fntopo(1); // assuming 1 as parent I guess it will be parent otherwise we will figure it out
    }
    
    topo.push_back(0);

    l(i,0,topo.size()) cout<<topo[i]<<" ";
    reverse(topo.begin(),topo.end());
    cout<<endl;
    l(i,0,topo.size()) cout<<topo[i]<<" ";
    // cout<<"yes I am here ";

    l(i,1,topo.size()){
        // cout<<topo[i]<<" ";
        if(dist[topo[i]] != 0){  // parent element(node) for others
            dist[topo[i]] = 0;
            fn(topo[i],0);
        }
        // cout<<"kya hua   ";
    }

    // cout<<"idhaaaaar ";

    cout<< maxi <<" ";

    // cout<< mxv(dist);



}