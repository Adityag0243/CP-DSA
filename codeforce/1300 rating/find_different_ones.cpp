#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define a(all) (a.begin(),a.end())
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        l(i,0,n) cin>>v[i];

        // l(i,0,n) cout<<v[i]<<" ";
        // cout<<endl;

        vector<int> diff(n);
        diff[0]=1;
        l(i,1,n){
            diff[i]=diff[i-1];
            if(v[i]!=v[i-1]) diff[i]++;
        }
        // l(i,0,n) cout<<diff[i]<<" ";
        // cout<<endl;
        
        int k;
        cin>>k;
        while(k--){
            int l,r;
            cin>>l>>r;

            if( diff[l-1] == diff[r-1] ){
                // cout<<"Answer ---:--   ";
                cout<<-1<<" "<<-1<<endl;
            }
            else{
                if(v[l-1] == v[r-1]){
                    r = lower_bound(diff.begin(),diff.end(),diff[r-1])-diff.begin();
                    // cout<<"value of r: "<<r<<"  ";
                }
                // cout<<"Answer ---:--   ";
                cout<<l<<" "<<r<<endl;
            }
        }
        
    }
}