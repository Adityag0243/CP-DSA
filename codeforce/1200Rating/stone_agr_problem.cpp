#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define ll int
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;




int main() {
	int n,q;
    cin>>n>>q;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    
    // int prev=0;
    ll sum=0;
    int x2=0;
    l(i,0,n) sum+=v[i];
    // int t;
    // cin>>t;
    // if(t==1){
    //     int i,x;
    //     cin>>i>>x;
    //     sum-=v[i-1];
    //     sum+=x;
        

    // }
    


    vector<int> pos;    
    l(i,0,n){
        pos.push_back(i+1);
    }
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int i,x;
            cin>>i>>x;
            bool check=false;
            if(!pos.empty()){
                l(k,0,pos.size()){
                    if(i==pos[k]){
                        check=true;
                        break;
                    }
                }
            }
            if(check) sum-=v[i-1];
            else sum-=x2;
            sum+=x;
            v[i-1]=x;
            pos.push_back(i);
            cout<<sum<<endl;

        }else{
            int x;
            cin>>x;
            sum=n*x;
            x2=x;
            cout<<sum<<endl;
            pos.clear();
        }
        // cout<<"After:  ";
        // l(k,0,n) cout<<v[k]<<"  ";
        // cout<<endl;
    }
    

}
