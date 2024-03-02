// 2 4 6 9 1 7 4 0 8  find the no of pair so that there sum is k=8

#include <bits/stdc++.h>
using namespace std;

int countpair(int k,vector<int> &v){
    int j=0;
    for(int i=0;i<v.size();i++){
        for(;j<v.size();j++){

        }
    }

}




int main(){
    int t;
    cin>>t;
    vector<int> v;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    int k;
    cin>>k;
    cout<<countpair(k,v);

}