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
    int n , m;
    cin >> n >> m;
    vvi grid(n, vi(m));
    l(i,0,n) l(j,0,m)
    {
        char c;
        cin >> c;
        if( c == '.') grid[i][j] = 0;
        else grid[i][j] = -1;
    }


    l(i,0,n) l(j,0,m)
    {
        if(grid[i][j] == -1) continue;
        int cnt = 0;
        if(i-1 >= 0 && grid[i-1][j] != -1) cnt++; 
        if(i+1 < n  && grid[i+1][j] != -1) cnt++; 
        if(j+1 < m  && grid[i][j+1] != -1) cnt++; 
        if(j-1 >= 0 && grid[i][j-1] != -1) cnt++; 

        grid[i][j] = 4-cnt;  // side's contribution to perimeter....
    }

    // cout << endl; 
    // l(i,0,n){
    //     l(j,0,m)
    //     {
    //         cout << grid[i][j] << "  ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;


    int peri = 0;
    int area = 0;

    queue< pair<int,int> > q;
    l(i,0,n) l(j,0,m){
        if(grid[i][j] < 0)  continue;
        q.push({i,j});
        int p = grid[i][j];
        int a = 1;
        grid[i][j] = -1;

        while( !q.empty() ){
            int xi = q.front().x;
            int yj = q.front().y;
            q.pop();

            if(xi-1 >= 0 && grid[xi-1][yj] >= 0){
                q.push({ xi-1, yj});
                p += grid[xi-1][yj];
                a += 1;
                grid[xi-1][yj] = -1;
            }
            if(xi+1 < n  && grid[xi+1][yj] >= 0){
                q.push({ xi+1, yj});
                p += grid[xi+1][yj];
                a += 1;
                grid[xi+1][yj] = -1;
            }
            if(yj+1 < m  && grid[xi][yj+1] >= 0){
                q.push({ xi, yj+1});
                p += grid[xi][yj+1];
                a += 1;
                grid[xi][yj+1] = -1;
            }
            if(yj-1 >= 0 && grid[xi][yj-1] >= 0){
                q.push({ xi, yj-1});
                p += grid[xi][yj-1];
                a += 1;
                grid[xi][yj-1] = -1;
            }

            
            // cout << p << " " << a <<"  , ";

        }
        // cout << p << " "  << a  <<  " p and a on i and j " << i << " " << j << "\n";
        if( p >= peri){
            if( p == peri){
                area = max(area, a);
            }else{
                peri = p;
                area = a;
            }
        }
    }

    cout << peri << " " << area << endl;
    return 0;
}