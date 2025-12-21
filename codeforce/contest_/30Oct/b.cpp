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
        vector<string> v(n);


        int h = 0;
        for(int i = 0; i < n; i++) cin >> v[i];
        for( auto s : v){
            for( auto c : s ){
                if( c == '#') h++;
            }
        }


        bool flag = false;

        //  R D
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < n ; j++){
                if ( v[i][j] == '#' ){

                    // D R
                    int cnt = 1;
                    int r = i, c = j;
                    while( r < n && c < n){
                        if( r + 1 < n  ){
                            if(v[r+1][c] == '#') {
                                cnt++;
                                // v[r+1][c] = '.';
                            }
                            if( c + 1 < n && v[r+1][c+1] == '#'){
                                cnt++;
                                // v[r+1][c+1] = '.';
                            }
                        }
                        r++;
                        c++;
                    }
                     if( cnt == h ) flag = true;
                    // cout << cnt << " ";


                    //  R D
                    cnt = 1;
                    r = i, c = j;
                    while( r < n && c < n){
                        if( c + 1 < n  ){
                            if(v[r][c+1] == '#'){
                                cnt++;
                                // v[r][c+1] = '.';
                            }
                            if( r + 1 < n && v[r+1][c+1] == '#'){
                                cnt++;
                                // v[r+1][c+1] = '.';
                            }
                        }
                        r++;
                        c++;
                    }
                     if( cnt == h ) flag = true;
                    // cout << cnt << " ";

                    // D L
                    cnt = 1;
                    r = i, c = j;
                    while( r < n && c >= 0){
                        if( r + 1 < n ){
                            if(v[r+1][c] == '#'){
                                cnt++;
                                // v[r+1][c] = '.';
                            }
                            if( c - 1 >= 0 && v[r+1][c-1] == '#'){
                                cnt++;
                                // v[r+1][c-1] = '.';
                            }
                        }
                        r++;
                        c--;
                    }
                     if( cnt == h ) flag = true;

                    // cout << cnt << " ";
                    // L D
                    cnt = 1;
                    r = i, c = j;
                    while( r < n && c >= 0){
                        if( c - 1 >= 0 ){
                            if(v[r][c-1] == '#'){
                                cnt++;
                                // v[r][c-1] = '.';
                            }
                            if( r + 1 < n && v[r+1][c-1] == '#'){
                                cnt++;
                                // v[r+1][c-1] = '.';
                            }
                        }
                        r++;
                        c--;
                    }
                    // cout << cnt << " ";
                    if( cnt == h ) flag = true;




                    if( h <= 4 ){
                        // cout << "YES ...   ";
                        cnt = 1;
                        if( i+1 < n && v[i+1][j] == '#') cnt++;
                        if( j+1 < n && v[i][j+1] == '#') cnt++;
                        if( i+1 < n && j+1 < n && v[i+1][j+1] == '#') cnt++;
                        // cout << cnt << " " ;
                        if(cnt == h) flag = true;
                        
                    }

                    i = n+1; break;
                }
            }
        }

        if(flag || h == 0) yes
        else no



    }
    return 0;
}