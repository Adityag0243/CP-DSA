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
        string s; cin >> s;
        

        bool flag = true;
        if(s[0] == '1' || s[n-1] == '1') flag = false;
        for(int i = 0; i <n ; i++){
            if( ( v[i] == 1 || v[i] == n)  && s[i] == '1' ) flag = false;
        }
        
        if(flag){
            int a1 = 0, an = 0;
            for(int i = 0; i <n ; i++){
                if(v[i] == 1) 
                    a1=i+1; 
                else if(v[i] == n) 
                    an = i+1;
            }
            
            cout << 5 << endl;
            cout << 1 << " " << n << endl; 
            cout << 1 << " " << a1 << endl;
            cout << 1 << " " << an << endl;
            cout << a1 << " " << n << endl;
            cout << an << " " << n << endl;
            
        }else cout << -1 << endl;
    }
}