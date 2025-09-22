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

int fn(int n){
    return (n * (n+1))/2;  
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,k; cin >> n >> k;
        string s, b; cin >> s >> b;
        set<char> sc; 
        l(i,0,n) sc.insert(s[i]);
        map<char, int> mp;
        int i = 0;
        for(char c : sc) mp[c] = i++;

        int ans = 0;

        for(int mask = 0; mask < ( 1 << (mp.size())); mask++){
            if(__builtin_popcount(mask) <= k){
                int cans = 0;
                int pt1 = 0, pt2 = 0;
                while(pt2 < n){
                    if( b[pt2] == s[pt2] ||  (( mask >> (mp[s[pt2]]) ) & 1 )) {
                        pt2++;
                    }else{
                        cans += fn(pt2-pt1);
                        pt2++;
                        pt1 = pt2;
                    }

                    if(pt2 == n){
                        cans += fn(pt2-pt1);
                    }

                    // if(mask == 7) cout << cans << " ";
                    
                }
                // cout << mask << " " << cans << endl;
                ans = max(ans, cans);
            }
        }

        cout << ans << endl;


    }
    return 0;
}