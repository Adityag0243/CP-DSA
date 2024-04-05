#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
       int n;
        cin>>n; 
        vector<int> v(n);
        vector<int> v1;
        
        for(int i=0;i<n;i++){
            int a;
            cin>>v[i];
            if(v[i]==0){
                a=i;
                v1.push_back(a);
            }
        }
        
        if(v.size()==v1.size() && v1.size()==1){
            cout<<0<<endl;
            continue;
        }
        
        
        
        int ans=v1.size()+1;
        if(v1.size()>0)
        if(v1[0]==0) ans-=1;
        
        if(v1.size()>1)
        if(v1[v1.size()-1]==n-1) ans-=1;
        
        if(v1.size()>1)
        for(int i=1;i<v1.size();i++){
            if(v1[i]==v1[i-1]+1) ans-=1;
            
        }
        
        for(int i=0;i<n;i++){
            if(v[i]==0){
                continue;
            }
        }
        
        

    }
    

}