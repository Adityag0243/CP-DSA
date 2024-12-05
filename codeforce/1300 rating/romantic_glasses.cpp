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
    fastio
    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vi v(n+1);
        v[0] = 0;
        l(i,1,n+1) cin >> v[i];
        map<int,pair<int,int>> mp;
        mp[0] = {1,2}; // even index
        bool check = false;
        l(i,1,n+1){
            v[i] -= v[i-1];
            // cout<<v[i]<<" ";
        
            if( (v[i] == 0) || (mp.find(v[i]) != mp.end() && i%2 == ((i&1) ? (mp[v[i]].first != -1) : (mp[v[i]].second != -1) - 1 )) ||  (mp.find(-1*v[i]) != mp.end() && i%2 == ((i&1) ?   (mp[-1*v[i]].second != -1) : (mp[-1*v[i]].first != -1)-1 ))  ){

                check = true;
                break;
            }else if( mp.find(v[i]) != mp.end() ){
                if(i&1){
                    mp[v[i]].first = 1;  
                }else mp[v[i]].second = 2; 
            }
            else{
                if(i&1){
                    mp[v[i]].first  =  1;
                    mp[v[i]].second = -1; 
                }else{
                    mp[v[i]].first = -1;
                    mp[v[i]].second = 2; 
                }
                
            }
        }

        if(check) yes
        else no
    }
}