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


vi v(1e6+2,-1);



int fn( string s){
    int num = stoi(s);
    int cnt = 0;
    l(i,0,s.size()) if(s[i] != '0') cnt++;

    if(cnt == 0) return 0;

    if(v[stoi(s)] != -1) return v[stoi(s)];

    cnt = INT_MAX;
    int original = num;
    l(i,0,s.size()){
        if(s[i] == '0') continue;
        num = original - (int)(s[i] - '0');
        cnt = min(cnt, fn(to_string(num)));
    }
    v[stoi(s)] = 1 + cnt;
    return v[stoi(s)];
}


signed main(){
    int n; cin >> n;
    
    string s = to_string(n); 
    fn(s);
    // l(i,0,n+1) cout << v[i] << " ";
    cout << v[n];
    return 0;
}