#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

int g(int a){
    if(a<10) return a;
    else{
        int multi=1;
        while(a){
            if(a%10) multi*=(a%10);
            a/=10;
        }
        return g(multi);
    }
}

int main(){
    #define limit 1e6+1
    vector<int> gn;
    l(i,0,limit) gn.push_back(i);
    l(i,0,limit){
        if(gn[i]==i) gn[i]=g(i);
        for(int j=10;j<1e6 && i!=0;j*=10){
            if(i<j){
                gn[j+i]=gn[i];
            }
        }
    }

/////////////////////////////////

    vector<int> v[10];
    l(i,0,10){
        l(j,0,limit)
            v[i].push_back(0);
    }

//////////////////////////////////
    l(i,1,limit){
        l(j,0,10) v[j][i]=v[j][i-1];
        v[gn[i]][i]++;
    }


    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;  
        cout<<v[k][r]-v[k][l-1]<<endl;
    }



}