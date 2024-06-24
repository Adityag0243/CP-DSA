#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
#define float double

bool check(float t,vector<pair<float,float>> &v ,int n){
    
    float orl=1e-18;  //overlap region low
    float orh=1e18;   //overlap region high
    l(i,0,n{
        float x = v[i].first - (v[i].second*t);
        float y = v[i].first + (v[i].second*t);
        orl=max(orl,x);
        orh=min(orh,y);
    }
    return orl<=orh;
}
int main(){
    int n;
    cin>>n;
    vector<pair<float,float>> v;
    l(i,0,n){
        float a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    float low=1 , high=1e10;
    int itr=100;
    float ans=0;
    while(itr--){
        float mid = low + (high-low)/2;
        if(check(mid,v,n)){
            high=mid-1;
            ans=mid;
        }
        else low=mid+1;
        if(abs(high-low)<1e-7) break;
    }
    cout<<fixed<<setprecision(6)<<ans;

}