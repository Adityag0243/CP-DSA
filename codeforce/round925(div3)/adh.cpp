#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)


int main(){
    freopen("input.in","r",stdin);
    freopen("a.out","w",stdout);
    int t;
    cin>>t;
    l(j,1,t+1){
       
        double n,p;
        cin>>n>>p;
        p/=100;
        cout<<"Case #"<<j<<": ";
        cout <<setprecision(15) <<  100*(pow(p,(n-1)/n) - p)<<endl;
    }
}