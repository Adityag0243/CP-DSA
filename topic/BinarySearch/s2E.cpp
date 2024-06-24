#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


int check(long double mid,long double n){

    long double lo=0;
    long double hi=1e6;
    int a=100;
    long double mi;
    while(a--){
        mi=(lo+hi)/2; 
        if(mi*mi<mid) lo=mi;
        else if((mi*mi-mid)<1e-6) break;
        else if(mi*mi>mid) hi=mi;
    }

    
    if((mid*mid + mi-n)<0) return 0;
    else if(abs(mid*mid+mi -n)<0.0000001){
        return 1;
    }
    if((mid*mid+mi)>n) return -1;
    
    
}



long double binary(long double n){
    long double low=1;
    long double high=n; 
    int a=100;  
    long double mid;

    while(a--){
        mid=(low+high)/2;
        if(check(mid,n)==1) return mid;
        else if(check(mid,n)==-1) high=mid-0.0000001;
        else low=mid+0.0000001;
    }
    return mid;
}




int main(){
    long double n;
    cin>>n;
    cout<<fixed<<binary(n)<<setprecision(15);
}