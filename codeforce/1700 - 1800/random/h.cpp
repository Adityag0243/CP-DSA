#include<bits/stdc++.h>
using namespace std;
#define int int64_t


signed main(){
    int t; cin >> t;
    while( t-- ){
        int n,m,k; cin >> n >> m >> k;

        vector<char> sb(n);
        for(int i = 0; i <n ; i++) cin >> sb[i];
        int ans = 0;
        while( m-- ){
            char s; cin >> s;
            if( s == 'A') continue;
            int l; cin >> l;
            l--;
            if( sb[l] == 'S'){
                sb[l] = 'A';
                ans++;
            }
        }
        cout << ans << endl;
    }
}