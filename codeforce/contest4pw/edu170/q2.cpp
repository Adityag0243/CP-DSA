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
        int n, k;
        cin >> n >> k;
        vi v(n);

        map<int,int> cnt;

        l(i, 0, n){
            cin >> v[i];
            cnt[v[i]]++; 
        }

        int ans = 0;
        int maxi = mxv(v); 
        int i = mnv(v);   
        int inner  = 0; 
        int enter = i;
        for( ; i<= maxi ;i ++){
            if(cnt.find(i)==cnt.end()){
                ans = max(ans , inner);
                inner = 0;
                enter = i+1;
            }else if( i >= enter +k){
                ans = max(ans , inner);
                inner -= cnt[enter];
                enter++;
                i--;
            }else{
                inner += cnt[i];
                ans = max(ans , inner);
            }
        }
        

        cout << ans << endl;
    }
}
