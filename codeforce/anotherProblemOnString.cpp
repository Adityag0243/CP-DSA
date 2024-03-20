#include <bits/stdc++.h>
using namespace std;



int main(){
    int k;
    cin>>k;
    string a;
    cin>>a;
    int kth=0,kth1=0;
    int count=0;
    for(int i=0;i<a.size();i++){
        int counter=0,check=1;
        for(int j=i;j<a.size();j++){
            
            if(a[j]=='1'){
                counter++;
                kth1=j;
            }
            if(counter>k){
                check=0;
                break;
            }
            if(check==1) kth=kth1;
            
        }
        if(counter<k){
            kth=0;
            kth1=0;//in dono ka to kaam hai hi nhi 
            break;
        }
        //cout<<kth<<kth1<<" ";
        count+=kth1-kth;
        if(kth1==kth) count++;

    }
    
    cout<<count;
    

}