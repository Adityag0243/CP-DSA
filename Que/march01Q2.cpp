#include <bits/stdc++.h>
using namespace std;






int main(){
    int t;
    cin>>t;
    vector<int> v;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    
   for(int i=0;i<t;i++){
       int count=0;
       count+=min(v[i]/15,v[i]/10,v[i]/6,v[i]/3,v[i]/1);
       v[i]%=15;
       count+=v[i]/10;
       v[i]%=10;
       count+=v[i]/6;
       v[i]%=6;
       count+=v[i]/3;
       v[i]%=3;
       count+=v[i]/1;
       
       cout<<count<<"\n";
       
   }
   
  
}
  

    
    