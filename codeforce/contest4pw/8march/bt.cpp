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
vector<int> prevGreaterElement(vector<int>& v);
vector<int> nextGreaterElement(vector<int>& v);

vector<int> prevGreatestElement(vector<int>& v) {
    int n = v.size();
    vector<int> prefixMax(n, -1);  
    int maxSoFar = -1;

    l(i, 0, n) {  // Traverse from left to right
        maxSoFar = max(maxSoFar, v[i]);
        prefixMax[i] = maxSoFar;
    }
    
    return prefixMax;
}


vector<int> nextGreatestElement(vector<int>& v) {
    int n = v.size();
    vector<int> suffixMax(n, -1);  
    int maxSoFar = -1;

    rl(i, 0, n) {  // Traverse from right to left
        maxSoFar = max(maxSoFar, v[i]);
        suffixMax[i] = maxSoFar;
    }
    
    return suffixMax;
}
signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    l(i,0,n) l(j,0,m) cin >> v[i][j];

    vvi rowNGreater, rowPGreater;
    l(i,0,n){
        rowNGreater.pb(nextGreaterElement(v[i]));
        rowPGreater.pb(prevGreaterElement(v[i]));
    }

    vvi colNGreater(m, vi(n)), colPGreater(m, vi(n));
    l(j,0,m){
        vi col;
        l(i,0,n) col.pb(v[i][j]);

        vi ng = nextGreaterElement(col);
        vi pg = prevGreaterElement(col);

        l(i,0,n) {
            colNGreater[j][i] = ng[i]; // Fix indexing
            colPGreater[j][i] = pg[i]; // Fix indexing
        }
    }

    int sum = 0;
    l(i,0,n){
        l(j,0,m){
            int a = rowNGreater[i][j];
            int b = rowPGreater[i][j];
            int c = colNGreater[j][i]; // Fix indexing
            int d = colPGreater[j][i]; // Fix indexing

            int mini = min({a,b,c,d});
            if(mini >= v[i][j]) sum += (mini - v[i][j]);
        }
    }

    cout << sum;
}
