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
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       vector<int> ans(6,-1);
       
       vector<vector<int>> v;
       l(i,0,3){
        vector<int> a(n);
        l(j,0,n) cin>>a[i];
        v.push_back(a);
       }
       l(i,0,3){
        l(j,1,n) v[i][j]+=v[i][j-1];
       }

       vector<vector<int>> vr;
       l(i,0,n){
        vector<int> a(3);
        l(j,0,3) cin>>a[i];
        vr.push_back(a);
       }


 
        ll sum=v[0][n-1]+2;
        sum/=3;
        int finder=0;

        l(i,0,n){
            if(max({v[0][i],v[1][i],v[2][i]})>=sum){
                lower_bound(vr.begin(),vr.end(),)
            }
        }











       int p,q,r;
       p=lower_bound(a.begin(),a.end(),sum)-a.begin();
       q=lower_bound(b.begin(),b.end(),sum)-c.begin();
       r=lower_bound(c.begin(),c.end(),sum)-c.begin();

       int mini=min({p,q,r});
       if(mini==n){
        cout<<-1<<endl;
        continue;
       }

       

       if(p==mini){
        finder=1;
        ans[0]=0+1;
        ans[1]=mini+1;
       }else if(q==mini){
        finder=2;
        ans[2]=0+1;
        ans[3]=mini+1;
       }else{
        finder=3;
        ans[4]=1;
        ans[5]=mini+1;
       }

      int pmin=mini;

       p=2*n;
       q=2*n;
       r=2*n;

       if(finder!=1) p=lower_bound(a.begin()+mini,a.end(),sum+a[mini])-a.begin();
       if(finder!=2) q=lower_bound(b.begin()+mini,b.end(),sum+b[mini])-b.begin();
       if(finder!=3) r=lower_bound(c.begin()+mini,c.end(),sum+c[mini])-c.begin();

       mini=min({p,q,r});
       if(mini==n){
        cout<<-1<<endl;
        continue;
       }

       if(p==mini){
        finder=1;
        ans[0]=pmin+1;
        ans[1]=mini+1;
       }else if(q==mini){
        finder=2;
        ans[2]=pmin+1;
        ans[3]=mini+1;
       }else{
        finder=3;
        ans[4]=pmin+1;
        ans[5]=mini+1;
       }

       if(ans[0]<0){
            if(a[n-1]-a[mini+1]>=sum){
                ans[0]=mini+2;
                ans[1]=n;
            }else{
                cout<<-1<<endl;
                continue;
            }
       }else if(a[2]<0){
            if(b[n-1]-b[mini+1]>=sum){
                ans[2]=mini+2;
                ans[3]=n;
            }else{
                cout<<-1<<endl;
                continue;
            }
       }else{
            if(c[n-1]-c[mini+1]>=sum){
                ans[4]=mini+2;
                ans[5]=n;
            }else{
                cout<<-1<<endl;
                continue;
            }
       }
       l(i,0,6) cout<<ans[i]<<" ";
       cout<<endl;


    }
}