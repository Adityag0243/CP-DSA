#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<string> v(n);
        l(i,0,n) cin>>v[i];
        if(n==1){
            while(k--){
                int x,y;
                cin>>x>>y;
                if(x==1 && y==1) cout<<0<<endl;
                else cout<<-1<<endl;
            }
            continue;
        }
        vector<ll> pre;
        l(i,0,n-1){
            if(v[i][0]==v[i+1][0] || v[i][0]==v[i+1][1] || v[i][1]==v[i+1][0] ||v[i][1]==v[i+1][1]) pre.push_back(1);
            else pre.push_back(0);
        }
        l(i,1,n-1){
            pre[i]+=pre[i-1];
        }
    
        
        if(n==2){
            while(k--){
                int x,y;
                cin>>x>>y;
                if(x==y) cout<<0<<endl;
                else if(pre[0]==1) cout<<1<<endl;
                else cout<<-1<<endl;
            }  
        }else{
            while(k--){
                int x,y;
                cin>>x>>y;
                if(x==y){
                    cout<<0<<endl;
                    continue;
                }
                x--;
                y--;
                if(x>y) swap(x,y);
                if(x==0? y==pre[y-1] : y-x == pre[y-1]-pre[x-1]) cout<<y-x<<endl;
                else if((y==n-1 ? pre[n-2]>pre[n-3] : n-y-1==pre[n-2]-pre[y-1]) && (x==0 ? true : x==pre[x-1])) cout<<n-y-1-x-1+n<<endl;
                else{
                    cout<<-1<<endl;
                }
            }
        }
        

    }
}