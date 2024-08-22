#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(c>b || d<a) cout<<1<<endl;
        else{
            if(a==c && b==d) cout<<b-a<<endl;
            else if(c<a && d>b) cout<<b-a+2<<endl;
            else if(a<c && b>d) cout<<d-c+2<<endl;
            else if(c<=a && d>=b) cout<<b-a+1<<endl;
            else if(a<=c && b>=d) cout<<d-c+1<<endl;
            else if(c>=a && c<=b && d>=b) cout<<b-c+1<<endl;
            else cout<<d-a+1<<endl;
        }


    }
}