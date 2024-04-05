#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    
    for(int l=0;l<t;l++){
        int a,b;
        cin>>a>>b;
        
        if(a<b){
            cout<<1<<endl;
            continue;
        }
        if(a==b){
            cout<<2<<endl;
            continue;
        }
        
        
        int b1=b;
        int m=a-b;
        int n=m-1;
        int k=m-1;
    
        // while(k<=m){
        //     m=n;
        //     int c;
        //     if(b1!=1){
        //         c=log(a)/log(b1);
        //     }else{
        //         b1++;
        //         c=log(a)/log(b1);
        //     }
        //     // cout<<"value of c: "<<c<<" "<<n<<" "<<b1<<endl;
        //     k=1+(b1-b)+c;
        //     n=min(m,k);
        //     b1++;
        // }
        
        
        
        int c=0;
        while(k<=m){
            m=n;
            
            if(b1!=1){
                c=log(a)/log(b1);
            }else{
                b1++;
                c=log(a)/log(b1);
            }
            // cout<<"value of c: "<<c<<" "<<n<<" "<<b1<<endl;
            k=1+(b1-b)+c;
            n=min(m,k);
            b1++;
            
            
            int p=a/pow(b1-1,c);
            if(b1==p){
                n=(b1-b)+c+2;
                break;
            }
            if(b1>p){
                n=(b1-b)+c+1;
                break;
            }
        }

        cout<<n<<endl;
    }
    

}