//  cses problem set EXPONENTIATION II 

#include <bits/stdc++.h>
using namespace std;

const int p=1000000007;

long long int modulo(int a,int b,int m){
    if(b==0){
        return 1%m;
    }
    if(b==1){
        return a%m;
    }
    int q;
    long long int k;
    
    q=(modulo(a,b/2,m)%m);
    k=(1LL*q*q)%m;
    
    if(b%2==0) return k;
    else return (k*a)%m;
        
}




int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int a,b,c;
        cin>>a>>b>>c;
    
        int ans=modulo(b,c,p-1);       //taking modulus to p-1 as modulo becomes one for p-1 for A^(2p+3) need to check only for A^3
        long long int real_ans=modulo(a,ans,p);
      
        cout<<real_ans<<endl;
       
    }
    

    
}