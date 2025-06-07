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
    // fastio;
    int n;
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];

    

    int ans = 0;
    int p1 = 0;
    int prev = v[0];
    int next = p1;
    int p2 = p1+1;

    while( p1 < n && p2 < n ){
        p2 = p1+1;
        prev = v[p1]; 
        bool flag = true;
        while( p2 < n && (flag || v[p2] > prev) ){
            if( v[p2] <= prev){
                next = p2;
                flag = false;
                if(p2-2 <= 0 && v[p2] > v[p2-2]+1){
                    prev = v[p2];
                }else if(p2-2 < 0 && v[p2] > 0){
                    prev = 1;
                }else prev++;
            }else{
                prev = v[p2];
            }
            p2++;
        }
        cout << p1 << " "<<p2 << "     ";
        // if(p1 == 0 && p2 != n) p1--;
        
        ans = max(ans, p2-p1);
        p1 = next;
    }
    if(n == 1) ans = 1;
    cout << ans << endl;
    return 0;
}