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
        int n2; cin >> n2;
        n2*= 2;
        vi v(n2); l(i,0,n2) cin >> v[i];
        srt(v);

        int n = n2 / 2;
        vi a(n); l(i,0,n) a[i] = v[i]; 
        vi b(n); l(i,0,n) b[i] = v[n2-1-i];


        vector<int> ans(n);
        ans[n-1] = smv(b) - smv(a);
        
        // int aminus = -a[n-1], aplus = a[n-1];
        // int bminus = -b[n-1], bplus = b[n-1];
        int aminus = 0, aplus = 0;
        int bminus = 0, bplus = 0;
    
        vi prefa = a; 
        l(i,1,n) prefa[i] += prefa[i-1];
        vi prefb = b; 
        l(i,1,n) prefb[i] += prefb[i-1];

        bool flag = true;
        bool even = true;

        rl(i,0,n){
            int sum_ = prefb[n-1] - prefa[n-1];
            if(even){
                sum_ += 2*aminus;
                sum_ -=  2*bplus;

                aplus  += a[i];
                bminus += b[i];
            }else{
                // cout << aplus << " " << bminus << " ";
                sum_ += 2*aplus;
                sum_ -= 2*bminus;

                aminus += a[i];
                bplus  += b[i];
            }
            ans[i] = sum_;

            even = !even;

        }

        for(int x : ans) cout << x << " ";
        cout << endl;




    }
    return 0;
}