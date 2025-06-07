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



// we will do decreasing operation first that too on minimum value...
// then making other elements equals to that mini value.....
// we will make biggest value == to lowest so that sum become lesser
// so sort first .. decrese the very first number to some particular value
// then equalize few element == to that mini value from behind(as they are greater..)

bool check(int m, int k, vi &v){
    int n = v.size();
    int c = n-1;     // how many larger value we need to make equals to mini

    while(c >= 0){
        if( c > m ) c--;
        else{
            int f = v[0] - (m - c);      // mini value
            int sum = (c + 1) * f;       // c from behind 1 very first elemnt will be equal to mini
            sum += (v[n-c-1] - v[0]);    // others as it ... to make this process I have taken prefix...
            if( sum <= k) return true;     
            c--;
        }
    }
    
    return false;
}



signed main(){
    fastio;
    int t;
    cin >> t;
    while(t--){
        int n , k;
        cin >> n >> k; 
        vi v(n);
        l(i,0,n) cin >> v[i];
        srt(v);
        l(i,1,n) v[i] += v[i-1];
        int total = v[n-1];

        if( total <= k){
            cout << 0 << endl;
        }else{
            

            int lo = 0;
            int hi = 1e10;
            int ans = 1e10;

            while( lo <= hi){
                int mid = (lo+hi)/2;
                // check if it is possible to make sum <= k in mid no of steps....
                // cout << "I am here... ";
                if( check(mid,k,v) ){
                    ans = mid;
                    hi = mid-1;
                }else{
                    lo = mid+1;
                }
            }

            cout << ans << endl;
        }
            
            

        
    }
    return 0;
}