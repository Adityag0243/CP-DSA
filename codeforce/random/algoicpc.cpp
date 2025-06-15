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
    vi v(n);  l(i,0,n) cin >> v[i];
    map<int, pair<int,int> > mp;   // factor --> minimum ele which has that factor

    l(i,0,n){
        for(int j = 1; j * j <= v[i]; j++){
            if( mp.find(j) != mp.end() ) mp[j] ={ min(mp[j].x, v[i]), mp[j].y + 1};
            else mp[j] = {v[i],1};

            if( j != v[i]/j ){
                if( mp.find(v[i]/j) != mp.end() ) mp[(v[i]/j)] = { min(mp[(v[i]/j)].x, v[i]), mp[(v[i]/j)].y +1 };
                else mp[(v[i]/j)] = {v[i],1};
            }
        }
    }

    int ans = -1;

    for(int i = 0; i<n ; i++){
        int val = v[i];
        for(int j = 2; j * j <= v[i]; j++){
            if( v[i] % j != 0) continue;
            if( mp.find(j) != mp.end()  && mp[j].y > 1 ){
                val = min(val, mp[j].x);
                break;
            }
        }
        for(int j = 2; j * j <= v[i]; j++){
            if( v[i] % j != 0) continue;
            if( mp.find(v[i]/j) != mp.end() &&  mp[v[i]/j].y > 1 ) val = min(val, mp[v[i]/j].x);
        }
        if(val != v[i]) ans += val;
    }

    cout << ans ;

    
    return 0;
}