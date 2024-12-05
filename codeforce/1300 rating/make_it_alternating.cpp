#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
#define MOD             998244353
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


vector<int> fact(200005);

signed main(){
    int t;
    cin >> t;
    

    fact[0] = fact[1] = 1;
    l(i,2,200005) fact[i] = (i*fact[i-1])%MOD;

    
    while(t--){
        string s;
        cin >> s;
        vi v;
        int i = 0;
        while(i<s.size()){

            int cnt = i;
            while( i<s.size() && s[i] == s[cnt]){
                i++;
            }
            v.pb(i-cnt);
        }
        int ans = 1;  //will store no of ways to select things needs to be eras

        l(i,0,v.size()) ans = (ans*v[i])%MOD;
        

        // now I have so many ways to select different collection of indices that need to be remove
        // and I want each collection to be ordered in different ways 

        // total different incides in each collections are n - v.size()   as v.size() is no of alternate sequence
        
        cout<<s.size()-v.size()<<" "<< (ans*(fact[s.size()-v.size()]))%MOD  <<"\n";
    }

}