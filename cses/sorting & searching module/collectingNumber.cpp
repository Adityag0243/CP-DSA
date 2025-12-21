#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<int> a(n);

    vector<int> mp(n+1);
    for(int i = 0; i < n; i++ ){
        cin >> a[i];
        mp[a[i]] = i;
    }
    int ans = 1;
    for( int val : a){
        if( val != 1 && mp[val - 1] > mp[val] ) ans++;
    }

    while( m-- ){
        int i,j; cin >> i >> j;
        i--, j--;
        set<int> impact;
        if(a[i] != 1) impact.insert(a[i]);
        if(a[i] != n) impact.insert(a[i] + 1);
        if(a[j] != 1)impact.insert(a[j]);
        if(a[j] != n)impact.insert(a[j] + 1);

        for( int val : impact ){
            if( mp[val - 1] > mp[val] ) ans--;
        }

        swap(a[i], a[j]);
        mp[a[i]] = i;
        mp[a[j]] = j;

        for( int val : impact ){
            if( mp[val - 1] > mp[val] ) ans++;
        }

        cout << ans << endl;

    }
    return 0;
}