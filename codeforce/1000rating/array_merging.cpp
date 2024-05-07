#include <bits/stdc++.h>
using namespace std;








int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        
        int n;
        cin>>n;
        
        vector<int> v1(n);
        vector<int> v2(n);
        for(int j=0;j<n;j++){
            cin>>v1[j];
        }
        for(int j=0;j<n;j++){
            cin>>v2[j];
        }
        
        
        
        
        int k=2*n+1;
        vector<int> vi[k];
        vector<int> vj[k];
        vector<int> vans(k);
  
        int j=0;
        while(j<n){
            int count=0;

            while(j<n){
                count++;
                if(v1[j]!=v1[j+1]){
                    j++;
                    break;
                }
                j++;
            }
            
            int a=v1[j-1];
            vi[a].push_back(count);
        }
 
        for(int l=0;l<k;l++){
            int a=vi[l].size();
            if(a==0){
                vi[l].push_back(a);
                
            }
           sort(vi[l].begin(),vi[l].end());
        }
        
        
        
        
        // *********************************** //
        j=0;
        while(j<n){
            int count=0;

            while(j<n){
                count++;
                if(v2[j]!=v2[j+1]){
                    j++;
                    break;
                }
                j++;
            }
            
            int a=v2[j-1];
            vj[a].push_back(count);
        }
 
        for(int l=0;l<k;l++){
            int a=vj[l].size();
            if(a==0){
                vj[l].push_back(a);
                
            }
           sort(vj[l].begin(),vj[l].end());
        }
        
        
        
        for(int l=0;l<k;l++){
            int a=vi[l].size();
            int b=vj[l].size();
            vans.push_back(vi[l][a-1]+vj[l][b-1]);
        }
        sort(vans.begin(),vans.end());
        cout<<vans[k-1]<<endl;
        
        
        
        
        
     
        
        
        

    }
}