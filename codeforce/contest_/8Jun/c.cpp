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
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        vi v(n); l(i,0,n) cin >> v[i];
        
        int ans = 1;
        set<int> s1;
        set<int> s2;
        s1.insert(v[0]);
        
        int i = 1;
        int turn = 1;

        while(i < n ){
            if(turn == 1 && s1.empty()){
                ans++;
                turn = 0;
            }else if( turn == 0 && s2.empty()){
                ans++;
                turn = 1;
            }

            if( turn == 1 ){
                if( s1.find(v[i]) != s1.end() ){
                    s1.erase(v[i]);
                }
                s2.insert(v[i]);
            }else{
                if( s2.find(v[i]) != s2.end() ){
                    s2.erase(v[i]);
                }
                s1.insert(v[i]);
            }
            i++;
        }
        if(turn == 1 && s1.empty()){
            ans++;
            turn = 0;
        }else if( turn == 0 && s2.empty()){
            ans++;
            turn = 1;
        }

        cout << ans << endl;
    }
    return 0;
}