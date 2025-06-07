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


// is it possible make mid as answer from index i
int check(int mid, int i, int k, vi &v){
    
    
    int n = v.size();

    while( i < n && k >= 0){

        if(v[i] >= mid) return true;
        k -= (mid - v[i]);
        if(k < 0) return false;
        mid--;
        i++;

    }

    return false;
}


signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;

        vi v(n);
        l(i,0,n) cin >> v[i];

        int ans = mxv(v);

        int lo = ans;
        int hi = 1e9;

        while( lo <= hi ){
            int mid = (hi - lo)/2 + lo;
            
            bool flag = false;
            l(i,0,n-1){
                if( check( mid, i, k, v)){
                    flag = true;
                    break;
                }
            }

            if(flag){
                ans = max(ans,mid);
                lo = mid+1;
            }else{
                hi = mid-1;
            }

        }

        cout << ans << endl;
    }
    return 0;
}