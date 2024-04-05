#include <bits/stdc++.h>
using namespace std;

int checkAP(vector<int> &v){
    int check=0;
    if(2*v[1]==v[0]+v[2]) check=1;
    return check;
}


int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        vector<int> v(3);
        cin>>v[0]>>v[1]>>v[2];
        if((2*v[1]-v[0])%v[2]==0){
            int a=(2*v[1]-v[0])/v[2];
            if(a!=0) v[2]=a*v[2];
            if(checkAP(v)==1 && a!=0 && a>0){
            cout<<"YES"<<endl;
            // cout<<v[0]<<v[1]<<v[2];
            // cout<<"ok1";
            continue;
            }else{
                if(a!=0)
                v[2]/=a;
            }
        }
        if((v[2]+v[0])%2*v[1]==0 ){
            int a=(v[2]+v[0])/(2*v[1]);
            // cout<<v[2]<<v[1]<<v[0]<<a<<endl;
            if(a!=0) v[1]=a*v[1];
            // cout<<v[2]<<v[1]<<v[0];
            if(checkAP(v)==1 && a!=0 && a>0){
            cout<<"YES"<<endl;
            
            // cout<<"ok2";
            continue;
            }else {
                if(a!=0)
                v[1]/=a;
            }
        }
        if((2*v[1]-v[2])%v[0]==0 ){
            int a=(2*v[1]-v[2])/v[0];
            if(a!=0) v[0]=a*v[0];
            if(checkAP(v)==1 && a!=0 && a>0){
            cout<<"YES"<<endl;
            
            // cout<<"ok3";
            continue;
            }else{
                if(a!=0)
                v[0]/=a;
            }
        }
        cout<<"NO"<<endl;
    }
    

}