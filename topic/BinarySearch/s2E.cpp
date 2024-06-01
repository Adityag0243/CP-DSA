#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


// long double sqroot(long double n){
//     long double low=0;
//     long double high=1e6;
//     int a=1000;
//     long double mid;
//     while(a--){
//         mid=(low+high)/2;
//         if(fabs(mid*mid-n) < 1e-15) break;
//         else if(mid*mid>n) high=mid;
//         else low=mid;
//     }

     
// }

int check(long double mid,int n){

    long double lo=0;
    long double hi=1e6;
    int a=10000;
    long double mi;
    long double comp =0.0000001;
    while(a--){
        mi=(lo+hi)/2; 
        if((mi*mi-mid)<comp) break;
        else if(mi*mi>mid) hi=mi;
        else lo=mi;
    }
    
    
    if((mid*mid + mi)<n) return 0;
    else if(((mid*mid+mi-n))<(comp)){
        cout<<"hmmm ";
        cout<<mi<<"   ";
        return 1;
    }
    if((mid*mid+mi)>n) return -1;
    
    
}



long double binary(int n){
    long double low=1;
    long double high=n; 
    int a=10000;  
    long double mid;
    // cout<<sqroot(3.698232168829691)/100<<"  ";
    // cout<<check(3.6982321688,15.6)<<"  sahi hai?? ";
    while(a--){
        mid=(low+high)/2;
        if(check(mid,n)==1) return mid;
        else if(check(mid,n)==-1) high=mid-0.0000001;
        else low=mid+0.0000001;
    }
    cout<<"hmmii  ";
    return mid;
}




int main(){
    int n;
    cin>>n;
    cout<<fixed<<binary(n)<<setprecision(15);
}