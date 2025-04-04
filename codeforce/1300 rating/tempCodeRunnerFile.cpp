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





void bfs(vector<char> &color , vector<set<int>> &v){
    vector<bool> visited(100005,false);
    visited[1] = true;
    color[1] = 'r';
    queue<int> q;
    q.push(1);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        for( int neighbour : v[node]){
            if( !visited[neighbour] ){
                visited[neighbour] = true;
                color[neighbour] = color[node] == 'r' ? 'b' : 'r';
                q.push(neighbour);
            }
        }
    }
}

signed main(){
    int n;
    cin>>n;
    vector<char> color(n+1,'x');
    vector< set<int> >v(n+1);

    l(i,0,n){
        int a,b;
        cin >> a >> b;
        v[a].insert(b);
        v[b].insert(a);
    }
    bfs(color,v);
    int red=0;
    int blue=0;
    l(i,1,n+1)
    {
        if(color[i] == 'r') red++;
        else blue++;
    }
    
    cout<< red*blue - (n-1); // given n-1 edge already given --> red*blue total posibility
    
    
}