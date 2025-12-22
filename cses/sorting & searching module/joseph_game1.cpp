#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 1; i <= n; i++) v.push_back(i);


    int i = 0;  
    // O(N) + O(N/2) + O(N/4) ..... 1 === O(N);
    while( i != v.size() ){
        if( i % 2 == 0){
            v.push_back(v[i]);
        }else{
            cout << v[i] << " ";
        }
        i++;
    }
}