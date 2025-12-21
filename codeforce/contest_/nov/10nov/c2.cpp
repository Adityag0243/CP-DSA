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

int n;
vector<vector<int>> v(2, vector<int>(100005));


// dp lagana pending hai abhi....
void fn(int i, int j, int mn, int mx, map<int,int> &mp, vector<vector<pair<int,int>>> &dp){
    if( i == 2){
        if(j == 0 && mx >= mn){
            if(mp.find(mn) != mp.end()) mp[mn] = min(mx, mp[mn]);
            else mp[mn] = mx;
        }
        return;
    }
    if( j == n ){
        fn(i+1, 0, mn, mx, mp, dp);
        return;
    }
    fn(i, j+1, min(mn, v[i][j]), max(mx, v[i][j]), mp, dp);
    if(i == 0) fn(i+1, j, min(mn, v[i][j]), max(mx, v[i][j]), mp, dp);
}
signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n ; i++) cin >> v[0][i]; 
        for(int i = 0; i < n ; i++) cin >> v[1][i]; 

        map<int,int> s;
        vector<vector<pair<int,int>>> dp(3, vector<pair<int,int>> (n+3));
        fn(0,0,v[0][0], v[0][0], s, dp);
        set<pair<int,int>> ans;
        int c = 0;

        for( auto p : s ){
            for(int i = 1; i <= p.first && i <= 2*n; i++ ){
                for(int j = max(i,p.second); j <= 2*n; j++){
                    ans.insert({i,j});
                    c++;
                }
            }
        }

        cout << ans.size() << endl;        
    }
    return 0;
}