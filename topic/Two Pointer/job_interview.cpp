#include<bits/stdc++.h>    // NOT SOLVED

using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n+m+1),b(n+m+1);
        l(i,0,n+m+1) cin>>a[i];
        l(i,0,n+m+1) cin>>b[i];

        int len=n+m+1;
        vector<ll> p,pt;
        vector<ll> t,tp;
        l(i,0,len){
            if(a[i]>b[i]){
                p.push_back(1ll*a[i]);
                pt.push_back(1ll*b[i]);
            }
            else{
                t.push_back(1ll*b[i]);
                tp.push_back(1ll*a[i]);
            }
        }

        l(i,1,p.size()){
            p[i]+=p[i-1];
            pt[i]+=pt[i-1];
        }
        l(i,1,t.size()){
            t[i]+=t[i-1];
            tp[i]=tp[i-1];
        }


        l(i,0,p.size()){
            cout<<p[i]<<" ";
        }
        l(i,0,t.size()) cout<<t[i]<<" ";
        cout<<endl;





        
        ll ans;

        l(i,0,len){
            ll sump=p[p.size()-1],sumt=t[t.size()-1];
            int kami=0;   // kis taraf kami hai programmer taraf ya tester ki taraf

            
            if(a[i]>b[i]){
                sump-=a[i];
                if((n&m)==0){
                    if(n==0){
                        ans=sumt+pt[pt.size()-1]-b[i];
                    }else{
                        ans=sump+tp[tp.size()-1];
                    }
                }else if(n==p.size()-1 && m==t.size()){
                    ans=(sump+sumt);
                }
                else if(n>p.size()-1){
                    kami=n+1-p.size();
                    sump+=(tp[tp.size()-1] - tp[tp.size()-1-kami]);      
                    sumt-=(t[t.size()-1] - t[t.size()-1-kami]);  
                    ans=(sump+sumt);
                }else{
                    kami=m-t.size();
                    sump-=(p[p.size()-1]-p[p.size()-1-kami]);
                    sumt+=(pt[pt.size()-1]-pt[pt.size()-1-kami]);
                    ans=(sump+sumt);
                }
            }else{
                sumt-=b[i];
                if((n&m)==0){
                    if(n==0){
                        ans=sumt+pt[pt.size()-1];
                    }else{
                        ans=sump+tp[tp.size()-1]-a[i];
                    }
                }else if((n==p.size() && m==t.size()-1)){
                    ans=(sump+sumt);
                }
                else if(n>p.size()-1){
                    kami=n-p.size();
                    sump+=(tp[tp.size()-1] - tp[tp.size()-1-kami]);      
                    sumt-=(t[t.size()-1] - t[t.size()-1-kami]); 
                    ans=(sump+sumt);
                }else{
                    kami=m+1-t.size();
                    sump-=(p[p.size()-1]-p[p.size()-1-kami]);
                    sumt+=(pt[pt.size()-1]-pt[pt.size()-1-kami]);
                    ans=(sump+sumt);
                }
            }
            cout<<ans<<" ";

        }
        cout<<endl;
    }
}