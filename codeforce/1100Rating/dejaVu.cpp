#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,k;
        cin>>n>>k;
        
        vector<int> v(n);
        
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        sort(v.begin(),v.end());
        int p1=0,p2=n-1;  //two pointer 1 from starting 2 from end
        
        
        for(int j=0;j<k;j++){
            if(p1+1<p2){
                cout<<"hellllo"<<v[p1]<<" "<<v[p1+1]<<" "<<v[p2]<<"   ";
                if(v[p1]+v[p1+1]<v[p2]){
                    v[p1]=0;
                    v[p1+1]=0;
                    p1+=2;
                }else{
                    v[p2]=0;
                    p2--;
                }
            }else{
                v[p2]=0;
            }
            
            
        for(int m=0;m<n;m++){
            cout<<v[m]<<" ";
           
        }
        cout<<endl;
            
            
        }
        
        long long int sum=0;
        for(int j=0;j<n;j++){
            // cout<<v[i]<<" ";
            sum+=v[j];
        }
        
        cout<<sum<<endl;
 

        
        

    }

}