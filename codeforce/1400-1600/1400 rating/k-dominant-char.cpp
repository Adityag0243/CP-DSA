#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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

int main(){
    fastio;

    string s;
    cin >> s;
    vi v[26];

    l(i,0,26){
        v[i].pb(-1);
    }
    l(i,0,s.size()){
        v[s[i]-'a'].pb(i);
    }
    l(i,0,26){
        v[i].pb(s.size());
    }
    int minima = INT_MAX;
    l(i,0,26){
        int maxima=INT_MIN;
        l(j,1,v[i].size()){
            // cout << 1 << endl;
            maxima = max (maxima , v[i][j]-v[i][j-1]);
        }
        minima = min(minima,maxima);
    }
    cout << minima << endl;

    return 0;
}