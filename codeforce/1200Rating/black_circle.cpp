#include<bits/stdc++.h>          //not solved
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
#define all(v) v.begin(),v.end()

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll> x(n);
        vector<ll> y(n);
        l(i,0,n){
            cin>>x[i]>>y[i];
        }
        ll x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        ll dist=abs((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
        // cout<<"dist: "<<fixed<<dist<<"  ";
        bool check= true;
        l(i,0,n){
            if(dist>=abs((x[i]-x2)*(x[i]-x2) + (y[i]-y2)*(y[i]-y2))){
                check=false;
                break;
            }
        }
        if(check) yes;
        else no;
    }
}