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


vector<int> prevGreatestElement(vector<int>& v) {
    int n = v.size();
    vector<int> pref(n, -1);  
    int maxi = -1;

    l(i, 0, n) { 
        maxi = max(maxi, v[i]);
        pref[i] = maxi;
    }
    
    return pref;
}


vector<int> nextGreatestElement(vector<int>& v) {
    int n = v.size();
    vector<int> suf(n, -1);  
    int maxi = -1;

    rl(i, 0, n) {  
        maxi = max(maxi, v[i]);
        suf[i] = maxi;
    }
    
    return suf;
}


signed main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int> (m));
    l(i,0,n) l(j,0,m) cin >> v[i][j];


    vvi rowNGreater, rowPGreater;
    l(i,0,n){
        rowNGreater.pb(nextGreatestElement(v[i]));
        rowPGreater.pb(prevGreatestElement(v[i]));
    }


    // vvi colNGreater(n, vector<int>(m));
    // l(j,0,m){
    //     vi col;
    //     l(i,0,n) col.pb(v[i][j]);
    //     vi colg = nextGreaterElement(col);
    //     l(i,0,n) colNGreater[i][j] = colg[i];
    // }


    // vvi colPGreater(n, vector<int>(m));
    // l(j,0,m){
    //     vi col;
    //     l(i,0,n) col.pb(v[i][j]);
        
    //     vi colg = prevGreaterElement(col);
    //     l(i,0,n) colPGreater[i][j] = colg[i];
    // }


    vvi colNGreater(n, vi(m, -1));
    vvi colPGreater(n, vi(m, -1));
    
    for (int j = 0; j < m; j++) {
        vi col(n);
        for (int i = 0; i < n; i++) col[i] = v[i][j];

        vi colNext = nextGreatestElement(col);
        vi colPrev = prevGreatestElement(col);

        for (int i = 0; i < n; i++) {
            colNGreater[i][j] = colNext[i];
            colPGreater[i][j] = colPrev[i];
        }
    }
    

    int sum = 0;

    l(i,0,n){
        l(j,0,m){
            int a = rowNGreater[i][j];
            int b = rowPGreater[i][j];
            int c = colNGreater[i][j]; //////...
            int d = colPGreater[i][j]; //////...

            int mini = min({a,b,c,d});
            if(mini >= v[i][j]) sum += (mini - v[i][j]);

            // cout << sum << " ";
        }
    }

    cout << sum ;

}