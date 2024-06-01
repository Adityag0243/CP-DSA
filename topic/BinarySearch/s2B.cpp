#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define rloop(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

bool check(vector<double> &v ,double mid ,int k){
    ll sum=0;
    loop(i,0,v.size()){
        sum+=((int)(v[i]/mid));
        if(sum>=k) break;
    }
    return sum>=k;
}


double binary(vector<double> &v,int n){
    double low=0;
    double high=1e9;
    double ans=1;
    int iter=1000;
    while(iter--){
        double mid=(high+low)/2;
        if(check(v,mid,n)){
            ans=mid;
            low=mid+1;
        }else high=mid-1;
    }
    return ans;
}


int main(){
	    int n,k;
	    cin>>n>>k;
	    vector<double> vc(n);
	    loop(i,0,n) cin>>vc[i];
	    cout<<fixed<<binary(vc,k)<<setprecision(6);
	        
}