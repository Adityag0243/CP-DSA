#include<bits/stdc++.h>
using namespace std;
#define int int64_t

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string a,b; cin >> a >> b;
        string f = "", s = "";
        for(int i = 0; i<n; i++){
            if( a[i] != b[i] ){
                f += a[i];
                s += b[i];
            }
        }
        int sz = f.size();
        bool flag = true;
        for(int i = 0; i < sz; i++ ){
            if( s[i] != f[(i+1)%sz]) flag = false;
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";

    }
}