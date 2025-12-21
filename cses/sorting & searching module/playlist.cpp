#include<bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v(n); for(int &i : v) cin >> i;

    set<int> s;
    int ans = 1;
    int ptr = 0;

    for(int i = 0; i < n; i++){
        while( s.find(v[i]) != s.end() ){
            s.erase(v[ptr++]);
        }
        s.insert(v[i]);
        ans = max(ans, (int)s.size());
    }

    cout << ans ;
}