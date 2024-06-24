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

int main() {
	int n = static_cast<int>(2 * 1e6);

    vector<ll> v(n + 1);
    l(i, 0, n + 1) v[i] = i;

	for(int i=2;i*i<=n;i++){
        if(v[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(v[j]==j) v[j]=i;
            }
        }
	}
    vector<ll> vsum(n+1);
    l(i,0,n+1) vsum[i]=0;

    l(i,2,1e6+1){
        if(v[i]==i){
            for(int j=i;j<=1e6;j++){
                // cout<<j<<"ok ";
                vsum[j]+=(j*i);
            }
        }
    }
    l(i,2,19) cout<<vsum[i]<<" ";
  

}
