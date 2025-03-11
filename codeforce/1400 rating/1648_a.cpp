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
#define MOD2            1000000007
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


int fn(vi &v){
    int sz = v.size();

    int firstone = 0;
    l(i,0,sz-1)  firstone += (sz-1-i)*v[i];

    int secondone = 0;
    l(i,1,sz)  secondone += i*v[i];

    return secondone - firstone;
}


signed main(){
    int t = 1;

    while(t--){
        int n , m;
        cin >> n >> m;
        map<int , vector<pair<int,int>> >mp;
        l(i,0,n){
            l(j,0,m){
                int val;
                cin >> val;
                mp[val].pb({i,j});
            }
        }


        int sum = 0;

        for(auto it : mp ){
            // it.second should be a vector in itself
            vector<int> v1;
            vector<int> v2;
            for(int i = 0 ; i< it.second.size() ; i++){
                v1.pb(it.second[i].first);
                v2.pb(it.second[i].second);
            }
            srt(v1);
            srt(v2);
            sum += fn(v1);
            sum += fn(v2);
        }

        cout<<sum<<endl;
        
    }
}