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
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int n,cnt;

double fn(int x, int y, int z, vector<vector<vector<double>>>& dp){
    if (x == 0 && y == 0 && z == 0) return 0;
    if (dp[x][y][z] != -1) return dp[x][y][z];

    double t = x + y + z;
    double res = 0;

    if (x > 0) res += x * fn(x - 1, y, z, dp);
    if (y > 0) res += y * fn(x + 1, y - 1, z, dp);
    if (z > 0) res += z * fn(x, y + 1, z - 1, dp);

    res += n;
    res /= t;

    return dp[x][y][z] = res;
}

signed main(){
    cin >> n;

    int x = 0 ,y = 0 ,z = 0;
    l(i,0,n){
        cin >> cnt;
        if(cnt == 1) x++;
        else if(cnt == 2) y++;
        else z++;
    }
    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1)));

    cout << fixed << setprecision(10) << fn(x,y,z, dp) << "\n";

    return 0;
}