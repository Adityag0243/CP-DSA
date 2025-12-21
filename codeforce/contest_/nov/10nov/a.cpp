#include<bits/stdc++.h>
using namespace std;
 
#define int int64_t
#define mod 1000000007 


signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for( int &i : v) cin >> i;
        sort(v.begin(), v.end());
        int i;
        for(i = 1; i < n-1; i += 2){
            if( v[i] != v[i+1] ) i = 5*n;
        }
        if( i == 5*n+2) cout << "NO\n";
        else cout << "YES\n";
    }
}