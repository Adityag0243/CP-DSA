//May be it will work fine...............


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
       int k=v[i];
       int counts=0;
       if(v[i]%15==0) counts=v[i]/15;
       else if(v[i]%10==0) counts=v[i]/10;
       else if(v[i]%6==0) counts=v[i]/6;
       else if(v[i]%3==0) counts=v[i]/3;
       else counts=v[i];
       
       
       
       
       int count=0;
       
       count+=v[i]/15;
       v[i]%=15;
       if(v[i]==8 && k!=8) {
           v[i]+=15;
           count--;
       }

       count+=v[i]/10;

       v[i]%=10;
       if(v[i]==2 && k!=2) {
           v[i]+=10;
           count--;
       }

       count+=v[i]/6;

       v[i]%=6;
       count+=v[i]/3;

       v[i]%=3;
       count+=v[i]/1;

       cout<<min(count,counts)<<"\n";
       
   }

}
  

    
    