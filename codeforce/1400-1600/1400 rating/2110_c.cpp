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

        int n; cin >> n;
        vi d(n); l(i,0,n) cin >> d[i];

        vector<pair<int,int>> lr(n);
        // vi dc = d;

        int c = 0;
        l(i,0,n){
            cin >> lr[i].x >> lr[i].y;
            if( d[i] == 1){
                c++;
                lr[i].x += c;
                lr[i].y -= c;
            }
        }

        // for(int x : d) cout << x << " ";
        // cout << endl;
        
        
        vi suf(n);
        suf[n-1] = lr[n-1].y;

        for(int i = n-2; i>=0; i--){
            suf[i] = min(suf[i+1], lr[i].y);
        }

        
        bool flag = true;
        int curh = 0;     

        for(int i = 0; i<n ; i++){
            cout << i << " : " << curh << " : " << lr[i].x << " " << lr[i].y << endl;
            if( d[i] == -1){
                if( (curh < lr[i].x  ||  curh + 1 <= suf[i] ) ){
                    d[i] = 1;
                }else d[i] = 0;   
            }
            curh += d[i];

            if(curh < lr[i].x || curh > lr[i].y){
                flag = false;
                break;
            }
        }
    
        // for(int x : d) cout << x << " ";
        cout << endl;

        if(flag) for(int x : d) cout << x << " ";
        else cout << -1 ;

        cout << endl;

    }
    return 0;
}