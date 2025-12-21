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
    int n,m,k; cin >> n >> m >> k;
    vi pos(n); l(i,0,n) cin >> pos[i];
    vi lch(m); l(i,0,m) cin >> lch[i];

    map<int,int> ind;
    l(i,0,n) ind[pos[i]] = i;

    int cnt = 0;
    for(int x : lch){
        cnt += (ind[x]/k) + 1;
        int i = ind[x];
        if(i == 0) continue;

        int prev = pos[i-1];
        swap(pos[i-1], pos[i]);
        ind[prev] = i;
        ind[x] = i-1;

    }

    cout << cnt;
    return 0;
}