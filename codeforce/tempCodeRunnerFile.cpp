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
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        l(i,0,n) cin>>a[i];
        // l(i,0,n){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        ll sum=0;
        vector<int> v;
        int prev=a[0];
        l(i,1,n){
            // cout<<a[i]<<" "<<prev<<" >> ";
            if(a[i]<prev){
                v.push_back(prev-a[i]);
                // cout<<v.front()<<"   ";
            }else prev=a[i];
        }


        if(v.size()==0)
        {
            cout<<0<<endl;
            continue;
        }
        // cout<<v.size()<<" <-- size\n";
        // l(i,0,v.size()){
        //     cout<<v[i]<<" ";
        // }

        srt(v);
        prev=0;
        int vsize=v.size();
        l(i,0,vsize){
            sum+=((v[i]-prev)*(vsize-i+1));
            prev=v[i];
        }
        cout<<sum<<endl;


        
        
    }

}
