#include<bits/stdc++.h>          //not solved
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
#define all(v) v.begin(),v.end()

ll NcR(int n, int r)
{

    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);

            p /= m;
            k /= m;
 
            n--;
            r--;
        }
    }
 
    else
        p = 1;
    return p;
}





int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> v(n),xr;
        l(i,0,n) cin>>v[i];
        vp(xyr);

        ll cnt=0;
    

        l(i,0,n){
        
            xyr.push_back(make_pair(v[i]%x,v[i]%y));
            xr.push_back(v[i]%x);
            
        }
        srt(xyr);
        l(i,0,n-1){
            if(xyr[i].first==0 && xyr[i+1].first==0){
                if(xyr[i].second==xyr[i+1].second) cnt++;
            }else{
                if(cnt) cnt++;
                break;
            }
            
        }
        if(cnt){
            cnt=NcR(cnt,2);
        }
        cout<<cnt<<"cnt begins\n";
        
        srt(xr);

        l(i,0,xr.size()) cout<<xr[i]<<"  ";
        cout<<endl; //
        l(i,0,xyr.size()) cout<<xyr[i].second<<"  ";
        cout<<endl; //

        int limit=lower_bound(all(xr),(x+1)/2)-xr.begin();
        cout<<limit<<"  is my limit\n";
        if(xyr[limit].first==(x+1)/2) limit++;

        for(int i=0;i<limit;i++){
            int l= lower_bound(all(xyr),make_pair(x-xyr[i].first,0))-xyr.begin();
            if(xyr[l].first!=x-xyr[i].first) continue;
            int r=upper_bound(all(xyr),make_pair(x-xyr[i].first,0))-xyr.begin();
            
            if(r==n) r--;
            if(xyr[r].first!=xyr[l].first) r--;
            cout<<l<<r<<" is l and r and cnt : ";

            for(int j=l;j<=r;j++){
                if(xyr[j].second==xyr[i].second) cnt++;
            }
            cout<<cnt<<"\n";
        }
        cout<<cnt<<endl;
        


        
        

        
    }
}