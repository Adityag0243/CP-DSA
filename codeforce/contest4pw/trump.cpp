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
   
    int n,m;
    cin>>n>>m;
    vector<pair<int,float>>pbc;
    l(i,0,n){
        float a;
        cin>>a;
        pbc.push_back(make_pair(0,a));
    }
    l(i,0,n){
        int a;
        cin>>a;
        pbc[i].first=a;
    }
    vector<pair<int,float>>pb;
    pb=pbc;
    sort(pb.rbegin(),pb.rend());
    int ind=n;

    l(i,0,n){
        if(pb[i].first<m){
            ind=i;
            break;
        }
    }
    float psum=0;
    l(i,0,ind){
        psum+=pb[i].second;
    }
    l(i,0,n){
        if(pbc[i].first>=m) cout<<fixed<<setprecision(9)<<pbc[i].second/psum<<" ";
        else cout<<(float)0<<" ";
    }
}