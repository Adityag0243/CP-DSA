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

bool solve(int n, string s){
    string org = s;

    l(i,1,n-1){
        if(s[i] == '1') continue;
        bool fix = false;

        if( i - 1 >= 0 && org[i-1] == '0')       fix = true;
        else if( i+1 <n     && org[i+1] == '0')  fix = true;
        else if( i-2 >= 0   && s[i-2] == '0')    fix = true;
        else if( i + 2 < n  && s[i+2] == '0'){
            fix = true;
            s[i+2] = '1';
        }

        if(!fix) return false;
    }
        
    return true;
}


signed main(){
    fastio
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        string st; cin >> st;

        if(solve(n,st)) yes
        else no
    }
}