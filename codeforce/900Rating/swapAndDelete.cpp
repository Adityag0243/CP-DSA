#include <bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        
        string s;
        cin>>s;


        int n_zero=0,n_one=0;
        for(int i;i<s.size();i++){
            if(s[i]==48) n_zero++;
            else n_one++;
        }
        
        int i=0;
        int c_zero=0,c_one=0;
        for(;c_one<=n_one && c_zero<=n_zero;i++){
            if(s[i]==48) c_one++;
            else c_zero++;
        }

        cout<<n-i;
        
        

    }
    

}