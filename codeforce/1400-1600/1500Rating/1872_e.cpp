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
        vi v(n);
        l(i,0,n) cin >> v[i];

        vi preXor(n,0);
        vi sufXor(n,0);

        preXor[0] = v[0];
        l(i,1,n){
            preXor[i] = preXor[i-1]^v[i];
        }

        sufXor[n-1] = v[n-1];
        rl(i,0,n-1){
            sufXor[i] = sufXor[i+1]^v[i];
        }

        string s;
        cin>>s;

        int zeroXor = 0;
        l(i,0,n) if(s[i]=='0') zeroXor^=v[i];

        int oneXor = preXor[n-1] ^ zeroXor; 

        int q;
        cin >> q;
        while(q--){
            int op;
            cin>>op;
            if(op==1){
                int l,r;
                cin>>l>>r;
                l--;
                r--;
                int lrXor = (preXor[n-1] ^ (l != 0 ? preXor[l-1] : 0) ) ^ ( r != n-1 ? sufXor[r+1] : 0); // Xor b/w l and r
                zeroXor ^= lrXor;
                oneXor ^=  lrXor;
            }else{
                int a;
                cin>> a;
                if(a==1) cout<<oneXor<<" ";
                else cout<<zeroXor<<" ";
            }
        }
        cout<<endl;
    }
}