// 2 4 6 9 1 7 7 4 0 8  find the no of pair so that there sum is k=8

#include <bits/stdc++.h>
using namespace std;

int countpair(int k,vector<int> &v){
    int j=v.size()-1;
    int count=0;
    for(int i=0;i<v.size();i++){
        for(;j>i;j--){  //very important why i tak taki 17 ka 71 bho count na hone lage
            if(v[i]+v[j]==k){
                //cout<<v[i]<<v[j]<<" ";
                count++;
            }
            if(v[i]+v[j]<k) break;
        }
    }
    return count;
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
    sort(v.begin(),v.end());
    cout<<countpair(k,v);

}