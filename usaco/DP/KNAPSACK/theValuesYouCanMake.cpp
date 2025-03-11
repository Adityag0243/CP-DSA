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

signed main(){

    int t = 1;

    while(t--){
        int n,k;
        cin >> n >> k;
        vi v(n);
        map<int,int> mp;

        l(i,0,n){
            int a;
            cin >> a;
            mp[a]++;
        }

        vector< set<int> > vs(k+1);
        vs[0].insert(0);

        // l(i,0,n){
        //     rl(j,1,k+1){
        //         if( j - v[i] >= 0 ){

        //             for(auto it : vs[j-v[i]]){
        //                 vs[j].insert(it);
        //                 vs[j].insert(it + v[i]);
        //             }
                    
        //         }
        //     }
        // }
        // 1 5 7
        // 3 2 1
        // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
        //        
        // for(auto it : mp){
        //     rl(j,1,k+1){
        //         if( j - v[i] >= 0 ){

        //             for(auto it : vs[j-v[i]]){
        //                 vs[j].insert(it);
        //                 vs[j].insert(it + v[i]);
        //             }

        //         }
        //     }
        // }

        cout << vs[k].size() << endl;
        for(auto it : vs[k]) cout << it << " ";
        cout << endl;


        
    }
}