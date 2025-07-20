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
        int n,q; cin >> n >> q;
        vi v(n); l(i,0,n) cin >> v[i];

        map<int,int> mp;
        l(i,0,n) mp[v[i]]++;     

        while(q--){
            int type; cin >> type;
            if(type == 1){
                int ind, x;
                cin >> ind >> x;

                mp[v[ind-1]]--;

                // erasing from map as i need to put this value if wants mex > current_value
                if(mp[v[ind-1]] == 0) mp.erase(v[ind-1]);

                v[ind-1] = x;
                mp[x]++; 

            }else{
                int k;
                cin >> k;

                // till what value I am getting values in my array....
                int prev = 0;

                for( auto it : mp){
               
                    if(k >= it.x - prev - 1){
                        k -= (it.x - prev - 1);    // used this much value of k 
                        prev = it.x;        // previous value which are not present is covered by k...
                    }else{
                        prev += k;
                        k = 0;
                        break;
                    }
                }

                if(k > 0) prev += k;

                cout << min(prev+1,n+1) << endl;
            }
        }
        

    }
    return 0;
}