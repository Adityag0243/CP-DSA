#include <bits/stdc++.h>
using namespace std;
#define vi              vector<int>
#define int             int64_t
#define endl            '\n'
#define pb              push_back
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main(){
    int t;
    cin >> t;
    while(t--){

        int n,q;
        cin >> n >> q;
        vi v(n);
        l(i,0,n) cin >> v[i];
        vi x(q);
        l(i,0,q) cin >> x[i];

        int lastBit = 31;
        l(i,0,q)
        {
            if(x[i] >= lastBit) continue;  // after one operation element won't be divisible by 2^xi or greater than xi power ever. Why ??

            l(j,0,n){
                if( v[j] % ( 1 << x[i] ) == 0){
                    v[j] += ( 1 << (x[i]-1));
                }
            }
            lastBit = x[i];
        }  

        l(i,0,n) cout << v[i] << " ";
        cout << endl;
        
    }
}