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
    int n, m;
    cin >> n >> m;
    vector<string> map_(n);
    

    l(i,0,n){
        cin >> map_[i];
    }


    queue< tuple<int, int, int> > enemy;
    
    vector<vector<int>> timer(n, vector<int>(m, n*m+1));
    
    l(i,0,n){
        l(j,0,m){
            if(map_[i][j] == 'M'){
                enemy.push(make_tuple(i,j,0));
                timer[i][j] = 0;
            }
        }
    }

    // cout <<"Going Inside enemy.... \n";

    
    while( !enemy.empty() ){
        // cout <<"Here ";
        auto it = enemy.front();   enemy.pop();
        
        int i = get<0>(it);
        int j = get<1>(it);
        int t = get<2>(it);

        if(i-1 >= 0 && map_[i-1][j] != '#' && timer[i-1][j] == n*m+1){
            timer[i-1][j] = min( timer[i-1][j], t+1);
            enemy.push(make_tuple(i-1,j,t+1));
        }
        if(i+1 <  n && map_[i+1][j] != '#' && timer[i+1][j] == n*m+1) {
            timer[i+1][j] = min( timer[i+1][j], t+1);
            enemy.push(make_tuple(i+1,j,t+1));
        }
        if(j-1 >= 0 && map_[i][j-1] != '#' && timer[i][j-1] == n*m+1) {
            timer[i][j-1] = min( timer[i][j-1], t+1);
            enemy.push(make_tuple(i,j-1,t+1));
        }
        if(j+1 <  m && map_[i][j+1] != '#' && timer[i][j+1] == n*m+1) {
            timer[i][j+1] = min( timer[i][j+1], t+1);
            enemy.push(make_tuple(i,j+1,t+1));
        }

    }

    // cout <<"Outside enemy.... \n";


    queue< tuple<int, int, int> > me;

    l(i,0,n){
        l(j,0,m){
            if(map_[i][j] == 'A'){
                me.push(make_tuple(i,j,0));
                timer[i][j] = 0;
                break;
            }
        }
    }


    pair<int, int> start = {-1,-1};


    bool flag = false;
    while( !me.empty() ){

        auto it = me.front();   me.pop();
        
        int i = get<0>(it);
        int j = get<1>(it);
        int t = get<2>(it);
        timer[i][j] = (-t);


        if(i == 0 || j == 0 || i == n-1 || j == m-1)
        {
            flag = true;
            start.first = i;
            start.second = j;
            break;
        }


        if(i-1 >= 0 && map_[i-1][j] != '#' && timer[i-1][j] > t+1){
            me.push(make_tuple(i-1,j,t+1));
        }
        if(i+1 <  n && map_[i+1][j] != '#' && timer[i+1][j] > t+1) {
            me.push(make_tuple(i+1,j,t+1));
        }
        if(j-1 >= 0 && map_[i][j-1] != '#' && timer[i][j-1] > t+1) {
            me.push(make_tuple(i,j-1,t+1));
        }
        if(j+1 <  m && map_[i][j+1] != '#' && timer[i][j+1] > t+1) {
            me.push(make_tuple(i,j+1,t+1));
        }
    }
    

    vector<char> ans;

    if(start.first != -1){
        int i = start.first;
        int j = start.second;
  
        

        while( map_[i][j] != 'A' ){

            if(i-1 >= 0 && timer[i-1][j] == timer[i][j] + 1){
                ans.push_back('D');
                i = i-1;
            }else if(i+1 < n && timer[i+1][j] == timer[i][j] + 1){
                ans.push_back('U');
                i = i+1;
            }
            else if(j-1 >=0 && timer[i][j-1] == timer[i][j] + 1){
                ans.push_back('R');
                j = j-1;
            }
            else if(j+1 < m && timer[i][j+1] == timer[i][j] + 1){
                ans.push_back('L');
                j = j+1;
            }

            

        }
        reverse(ans.begin(), ans.end());
    }

    if(flag){
        cout << "YES\n" << ans.size() << endl;
        for(auto it : ans) cout << it; 
    }else{
        cout << "NO\n";
    }

    return 0;
}