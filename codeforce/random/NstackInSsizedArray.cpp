#include <bits/stdc++.h> 
using namespace std; 
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int main() { 
    fastio
    // your code goes here 
    int n,s,q; cin >> n >> s >> q; 
    vector<int> ele(s);       // will store actual element 
    vector<int> pointer(n+1,-1);  // will store top element pos 

    vector<int> prev(s,-1); 
    vector<int> space(s); 
    for(int i = 0; i<s; i++)
    { 
        space[i] = s-i-1; 
    } 
    int ptrSpace = s-1; 
    while(q--){ 
        int type; cin >> type; 
        if( type == 1){ 
            int x,m;   cin >> x >> m; 
            if(ptrSpace == -1) cout << "False\n"; 
            else{ 
                ele[ space[ptrSpace] ] = x; 
                prev[space[ptrSpace] ] = pointer[m]; 
                pointer[m] = space[ptrSpace]; 
                ptrSpace--; cout << "True\n"; 
            } 
        }else{ 
            int m;   cin >> m; 
            if( pointer[m] == -1 ) cout << -1 << endl; 
            else{ 
                cout << ele[ pointer[m] ] << endl; 
                space[++ptrSpace] = pointer[m]; 
                pointer[m] = prev[ pointer[m] ]; 
            } 
        } 
    } 
}