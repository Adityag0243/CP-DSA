#include <bits/stdc++.h>
using namespace std;





int search(int a,int j,vector<int> &v){
    int ans=v.size();
    if(j==v.size()+1){
        return ans;
    }
    for(int i=j;i<v.size();i++){
        if(v[i]>a){
            ans=i;
            break;
        }
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        
        vector<int> v(n);
        vector<int> vcopy(k);
        for(int j=0;j<n;j++){
            cin>>v[j];
            if(j<k)
            vcopy[j]=v[j];
        }
        sort(vcopy.begin(),vcopy.end());
        
        
        if(n==2){
            if(vcopy[n-1]==v[k-1]){
                cout<<1<<endl;
            }else cout<<0<<endl;
            continue;
        }
          
        
        int firstlarge=search(v[k-1],0,v);
        if(vcopy[k-1]==v[k-1]){
            cout<<firstlarge-1<<endl;
        }else{
            int large2=min(search(v[k-1],firstlarge,v),k-1);
            
            cout<<max(firstlarge-1,large2-firstlarge)<<endl;
            
            
            
            
            
            
            
            
            // int secondlarge()
            // int pos1=search(vcopy[n-1],v);
            // if(pos>pos1)
            // cout<<max(pos1-1,n-1-pos1)<<endl;
            // else
            // cout<<pos1-pos-1<<endl;
            // int pos1=search(vcopy[n-1],v);
            // int pos2=search(vcopy[n-2],v);
            // if(pos>pos2)
            // cout<<max(pos1-1,pos2-1-pos1)<<endl;
            // else if(pos>pos1 && pos<pos2)
            // cout<<max(pos1-1,pos-pos1-1)<<endl;
            // else
            // cout<<pos1-pos-1<<endl;
            
        }
      

        
        
        
        
     
        
        
        

    }
}