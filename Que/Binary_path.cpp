#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> v1;
        vector<int> v2;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            v1.push_back(a);
        }
        // for(int j=0;j<n;j++){
        //     int a;
        //     cin>>a;
        //     v2.push_back(a);
        // }
        
        
        // for(int k=1;k<n-1;k++){
        //     v1[k]=min(v1[k]+v1[k+1],v1[k]+v2[k]);
        //     v2[k-1]=v2[k-1]+v2[k];
        // }
        
        int pointer=v1[0],count=1;
        for(int j=0;j<n;j++){
            cout<<v1[j]<<" ";
        }
        
        
        cout<<"\n";
        
        // for(int k=0;k<n-2;k++){
            
        //     if(v1[k+1]==v2[k]){
        //         count++;
        //         pointer=v1[k+1];
        //     }else if(v1[k+1]>v2[k]){
        //         pointer=v1[k+1];
        //     }else{
        //         pointer=v2[k];
        //         continue;
        //     }
        // }
        
        
        // if(pointer==v1[n-2]){
        //     if(v1[n-1]==v2[n-1]) count++;
        
        // }
        
        // cout<<count<<"\n";
        
        
        
    }
  
}
  

    
    