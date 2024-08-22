#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;


int main(){

    int n;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<1;
        return 0;
    }
    vector<int> v;
    int k=2;
    while(n>1){
        if(n%k==0){
            n/=k;
            v.push_back(k);
        }else k++;
    }

    ll a=1,b=1;
    if((v.size()&1)){
        l(i,0,v.size()/2-1){
            if(i&1) a*=(1ll*v[i]*v[v.size()-i-1]);
            else b*=(1ll*v[i]*v[v.size()-i-1]);
        }
        if(min(a,b)==a){
            a*=min(v[v.size()/2-1]*v[v.size()/2] , v[v.size()/2+1]);
            b*=max(v[v.size()/2-1]*v[v.size()/2] , v[v.size()/2+1]);
        }else{
            a*=max(v[v.size()/2-1]*v[v.size()/2] , v[v.size()/2+1]);
            b*=min(v[v.size()/2-1]*v[v.size()/2] , v[v.size()/2+1]);                      
        }
    }else{
        if(v.size()==2){
            a=v[0];
            b=v[1];
        }else
        l(i,0,v.size()/2){
            if(i&1) a*=(v[i]*v[v.size()-i-1]);
            else b*=(v[i]*v[v.size()-i-1]);
        }
    }
    cout<<a<<" "<<b;


    
    
}