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
    int n; cin >> n;
    string s; cin >> s;

    set<char> st;
    l(i,0,n) st.insert(s[i]);
    int dif = st.size();

    map<char, set<int> > mp;
    int ans = n;
    int p1 = 0;
    l(i,0,n){
        
        mp[s[i]].insert(i);
        if(mp.size() == dif) ans = min(ans, i-p1+1);
        while( mp.size() == dif && mp[s[p1]].size() > 1){
            ans = min(ans, i-p1);
            mp[s[p1]].erase(p1);
            if(mp[s[p1]].size() == 0) mp.erase(s[p1]);
            p1++;
        }
    }

    cout << ans << endl;


    return 0;
}