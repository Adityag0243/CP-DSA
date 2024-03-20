/* 01110100111101011110    k=3 flip any zero to 1 (k such operation allowed)so that we can get maximum consecutive length of 1's */ 


#include <bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter Binary Array or string ";
    string a;
    cin>>a;
    int k;
    cout<<"Enter k ";
    cin>>k;

    int ans=0;
    int op=0;
    int j=0;  //operation
    //cout<<"           "<<"i"<<" "<<"j"<<" "<<"a[i]"<<" "<<"op"<<" "<<"ans"<<"\n";
    for(int i=0;i<a.size();i++){
        // op=0;                             //pichhale me kitne operation ho chuka uska use krunga
        for(;j<a.size();j++){             // jaha tak j kam kr chuka tha use wapis kyu krna
            if(a[j]=='0') op++;
            if(op<=k) ans=max(ans,j-i+1);               //
            
            else{
                if(a[j]=='0') op--;
                //cout<<"phle ka op "<<op;
                if(a[i]=='0'){
                    op--;
                }        //one change here ,pichhala i not j 
                                        //agar zero tha to ek operation aur krne ko mil gaya is bar hme
                //cout<<i<<" "<<j<<" "<<a[i]<<"   "<<op<<"  "<<ans<<"\n";
                break;
            }
        }
    }
    cout<<"max length of 1's is : "<<ans;
    
}