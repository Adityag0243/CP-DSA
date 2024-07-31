//codeforces
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
    vector<ll> arr(n);
    l(i,0,n) cin>>arr[i];



    vector<ll> v(1e6);
    l(i,0,1e6) v[i]=i;
    for(ll i=2;i<1e6;i++){
        if(v[i]==i){
            for(ll j=i*i;j<1e6;j+=i) v[j]=i;
        }
    }
    vector<ll> prime;
    l(i,2,1e6){
        if(v[i]==i) prime.push_back(i);
    }






    ll ans=1;
    ll maxi=*max_element(arr.begin(),arr.end());


    for(int i=0;i<prime.size() && prime[i]<=maxi ;i++){
        int p=prime[i];
        int cnt=0;

        l(j,0,n){
            if( arr[j] % p != 0 ) cnt++;
            if(cnt>1) break;
        }
        if(cnt<2){
            ans*=p;
            l(j,0,n) arr[j]%p==0 ? arr[j]/=p : 0 ;
            i--;
        }
    }
    cout<<ans;
   
    
    
}