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
#define pb                  push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)         accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)         sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2          1000000007
#define x                  first
#define y                  second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)         for(int i=st;i<n;i++)
#define rl(i,st,n)       for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int n,k;
vi v(5001);
vi cold(5001);
vi hot(5001);


int fn(int last1, int last2, int i, vvi &cpu1){
    if( i == n) return 0;

    if( cpu1[last1][i] != 1e15 && cpu1[last2][i] != 1e15) return min(cpu1[last1][i], cpu1[last2][i]);

    int t =  ((last1 == v[i]) ? hot[v[i]] : cold[v[i]] )   + fn(v[i], last2, i+1, cpu1);
    int fr = ((last2 == v[i]) ? hot[v[i]] : cold[v[i]] )   + fn(last1, v[i], i+1, cpu1);
    
    return  cpu1[last1][i] = cpu1[last2][i] = min({cpu1[last2][i], cpu1[last1][i], t, fr});

}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        l(i,0,n) cin >>v[i];
        l(i,1,k+1) cin >> cold[i];
        l(i,1,k+1) cin >> hot[i];
        vvi cpu1(n+k+1, vi(n+k+1, 1e15));
        // vvi cpu2(n+k+1, vi(n+k+1, -1));
        
        cout << fn(0,0,0, cpu1) + 1 << endl;
        
    }
    return 0;
}