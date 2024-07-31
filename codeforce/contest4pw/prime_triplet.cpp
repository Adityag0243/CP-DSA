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
    ll n;
    cin>>n;
    if(n<38){
        no;
        return 0;
    }


    ll till=sqrt(n);
    vector<int> v(till+1);
    for(ll i=0;i<till+1;i++) v[i]=i;
   
    for(ll i=2;i<till+1;i++){
        if(v[i]==i){
            for(ll j=i*i;j<=till;j+=i) v[j]=i;
        }
    }

    vector<ll> psqr;
    for(ll i=3;i<till+1;i++){
        if(v[i]==i){  
            psqr.push_back(1ll*i*i);
        }
    }


    n-=4;


    
    l(i,0,psqr.size()){
        ll val=n;
        val-=psqr[i];
        int ind= lower_bound(psqr.begin()+i+1,psqr.end(),val)-psqr.begin();
        if(ind!=psqr.size() && psqr[ind]==val){
            yes;
            return 0;
        }  
    }
    no;
}