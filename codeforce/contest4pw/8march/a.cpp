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


vi dp(105,105);

void fn(int i, vector<vector<int>>& v, string s, int score){
    if(i == s.size()) return 0;
    int lb = lower_bound(all(v[s[i]-'a']), i) - v[s[i]-'a'].begin();
    lb--;
    int between = INT_MAX;
    if(lb >= 0) between = i - lb - 1;

    return dp[i] = min({
        dp[i],
        1 + fn(i+1,v,s),
    }
    )
}


signed main(){
    string s1;
    cin >> s1;
    
    string s = "";
    s += s1[0];
    l(i,1,s1.size()) if(s1[i] != s.back()) s += s1[i];

    vector<vector<int>> v;
    l(i,0,s.size()) v[s[i] - 'a'].pb(i);
    cout << 1 + fn(1,v,s, 1);
}