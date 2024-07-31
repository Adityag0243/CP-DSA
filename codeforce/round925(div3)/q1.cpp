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
    
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        l(i,0,n) cin>>v[i];
        ll sum=0;

        srt(v);
        int t=lower_bound(v.begin(),v.end(),0)-v.begin();  // no of negatives
        // cout<<t<<"  ";
        if(t>=k){
            l(i,0,k){
                v[i]*=(-1);
            }
            l(i,0,n){
                sum+=v[i];
            }
        }else{
            l(i,0,t){
                v[i]*=(-1);
            }
            srt(v);
            l(i,0,n){
                sum+=v[i];
            }
            k-=t;  // extra operation remains
            if(k&1){
                sum-=(2*v[0]);
            }
        }
        cout<<sum<<endl;
        
        
   
}