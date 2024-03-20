#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> v;

    vector<int>v1={11,2,13};
    vector<int>v2={41,15,6};
    v.push_back(v1);
    v.push_back(v2);
    sort(v[1].begin(),v[1].end());
    cout<<v[1].size();


}