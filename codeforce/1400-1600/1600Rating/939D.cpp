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

vi vis(26, 0);
set<int> adj[26];

void dfs(int i, int cmp){
    vis[i] = cmp;
    for( int child : adj[i]){
        if( !vis[child] ) dfs(child,cmp); 
    }
}

signed main(){
    int n; cin >> n;
    string s1,s2; cin >> s1 >> s2;
   
    for(int i = 0; i <n; i++ ){
        if( s1[i] == s2[i] ) continue;
        adj[s1[i]-'a'].insert(s2[i]-'a');
        adj[s2[i]-'a'].insert(s1[i]-'a');
    }

    int cmp = 0;
    for(int i = 0; i < n ; i++){
        if( !vis[s1[i]-'a'] ){
            cmp++;
            dfs(s1[i]-'a', cmp);
        }        
    }
    // for(char c : s1) cout << 
    // cout << cmp << "  : cmp\n";

    
    map<int, char> cmpChar;
    set< pair<char, char> > ans;

    for(int i = 0; i < n ; i++){
        if( s1[i] == s2[i] ) continue;
        if( cmpChar.find(vis[s1[i]-'a']) == cmpChar.end() ){
            cmpChar[vis[s1[i]-'a']] = s1[i];
        }

        if(cmpChar[vis[s1[i]-'a']] != s1[i]){
            ans.insert({cmpChar[vis[s1[i]-'a']], s1[i]});
        }
        if(cmpChar[vis[s1[i]-'a']] != s2[i]){
            ans.insert({cmpChar[vis[s1[i]-'a']], s2[i]});
        }
    }
    cout << ans.size() << endl;
    for( auto p : ans ) cout << p.x << " " << p.y << endl;
    

    return 0;
}