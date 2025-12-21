#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v;
    v.push_back(0);

    int i = 0, j = 0;
    while( i < n && j < n ){

        int c = 0;
        while( j < n && s[j] == 'v'){
            j++; c++;
        }
        if(c) v.push_back(c-1);
        v.push_back(-1); // for identifying 'o'...
        i = j+1;
        j++;
    }
    v.push_back(0);

    int sz = v.size();
    vector<int> pf = v;
    vector<int> sf = v;
    for(int i = 1; i < sz; i++){
        if(pf[i] == -1) pf[i] = 0;
        pf[i] += pf[i-1];
    }

    for(int i = sz-2; i >= 0; i--){
        if(sf[i] == -1) sf[i] = 0;
        sf[i] += sf[i+1];
    }

    int ans = 0;
    for(int i = 1; i < sz-1; i++){
        if( v[i] != -1) continue;

        ans += (pf[i-1] * sf[i+1]);
    }

    cout << ans << endl;
}