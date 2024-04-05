#include <bits/stdc++.h>         //pending
using namespace std;
int checker(int k , long long int n);

int checker(int k , long long int n){
    int check=0;
    
    while(n>0){
        if(k==n%10){
            check=1;
            break;
        }
        n/=10;
    }
    return check;
}

int fair(long long int n){
    int check=0;
    set<int> s;
    for(int i=1;i<10;i++){
            if(checker(i,n)==1){
                s.insert(i);
            }
    }

     
    long long int k;
    if(s.size()==1){
        k=*(s.begin());
    }
    else{
        k=lcm(*(s.begin()),*next(s.begin(),1));
        for(auto itr=next(s.begin(),2);itr!=s.end();itr++){
            k=lcm(k,*itr);
        }
    }   
    
    if(n%k==0) check=1;
    
    
    
    return check;
}




int main(){
    int t;
    cin>>t;
    long long int pn=0,pans=0;
    
    for(int l=0;l<t;l++){
        long long int n;
        cin>>n;
        set<int> s;
        // cout<<checker(1,n);
        
        for(int i=1;i<10;i++){
            if(checker(i,n)==1){
                s.insert(i);
            }
        }
        // cout<<*(s.begin())<<" ";
        
        long long int k;
        if(s.size()==1){
            k=*(s.begin());
        }
        else{
            k=lcm(*(s.begin()),*next(s.begin(),1));
            for(auto itr=next(s.begin(),2);itr!=s.end();itr++){
                k=lcm(k,*itr);
            }
        }
        
        
        long long int ans;
        if(n%k!=0)
        ans=(n/k+1)*k;
        else {
            ans=(n/k)*k;
            // cout<<ans<<endl;
            // continue;
        }
        
        
        for(long long int i=n;;i++){
            if(n==pn){
                cout<<pans<<endl;
                break;
            }
            if(fair(i)==1){
                cout<<i<<endl;
                pn=n;
                pans=i;
                break;
            }
        }
        
        
    
    }
    

}