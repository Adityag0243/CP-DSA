#include <bits/stdc++.h>
using namespace std;






int main(){
    int t;
    cin>>t;
    vector<int> v1;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    
    int k;
    cin>>k;
    vector<int> v2;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    int count=0;
    if(v1[t-1]+1<v2[0]){
        count=0;
        cout<<0;
        break;
    }
    for(int i=0;i<t;i++){
        if(v1[i])
    }
    
    
   
  
}
  

    
    