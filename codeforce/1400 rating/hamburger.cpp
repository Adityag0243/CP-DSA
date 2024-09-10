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


ll rb=0,rs=0,rc=0;   //required
ll ab,as,ac;
ll pb,ps,pc;
ll r;

ll check(ll cnt){
    return r >= max(1ll*0,(cnt*rb - ab)*pb) + max((cnt*rs - as)*ps , 1ll*0) + max(1ll*0,(cnt*rc - ac)*pc);
}




int main(){
    string s;
    cin>>s;
    
    l(i,0,s.size()){
        if(s[i]=='B') rb++;
        else if (s[i]=='S') rs++;
        else rc++;
    }



    cin>>ab>>as>>ac;


    cin>>pb>>ps>>pc;

    cin>>r;

    ll lo=0;
    ll hi=1e15;
    ll ans=0;

    while(lo<=hi){
        ll mid= lo + (hi-lo)/2;
        if(check(mid)){
            ans=mid;
            lo=mid+1;
        }else hi=mid-1;
        
    }

    cout<<ans;

}