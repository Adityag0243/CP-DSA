#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        int n;
        cin>>n; 
        vector<int> v(n);
        
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        
        

        sort(v.begin(),v.end());
        
        int pos;
        if(n%2==0) pos=n/2-1;
        else pos=n/2;
        
        int start=pos,end=n-1;
        int ans=start;
        
        while(start<end){
            int mid=start+(1+(end-start)/2);
            // cout<<mid;
            if(v[pos]==v[n-1]){
                ans=n;
                break;
            }else if(v[mid]>v[start]){
                ans=mid;
                // cout<<ans<<" ";
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        cout<<ans-pos<<endl;


    }
    

}