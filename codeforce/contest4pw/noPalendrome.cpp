#include <bits/stdc++.h>
using namespace std;
//remains not solved
int palendrome(int p1,int p2,string a){
    int check=1;
    while(p1<p2){
        if(a[p1]!=a[p2]){
            check=0;
            break;
        }
        p1++;
        p2--;
    }
    return check;
}




int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string a;
        cin>>a;
        set<string> ans;
        int p1=0;
        
        string m,n,c;
        
        for(int j=0;j<a.length();j++){
             m=a[p1];
             
            if(palendrome(p1,j,a)==0){
                n=a[j];
                m+=n;
            }else{
                p1=j;
                ans.insert(m);
                m.clear();
            }
        }
        
        if(ans.size()>1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
        
        

    }
}