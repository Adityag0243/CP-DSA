#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
        vector<int> arr(n);
        l(i,0,n) cin>>arr[i];

        vector<int> v[n];
        l(i,0,n) {
            v[i].push_back(INT_MIN);
            v[i].push_back(-1);
        }

        // 0 index --> maximum difference of indices , last index
        l(i,0,n){
            v[arr[i]-1][0]=max(v[arr[i]-1][0],i-v[arr[i]-1][1]);
            v[arr[i]-1][1]=i;
        }

        
        

        l(i,0,n){
            v[i][0]=max(v[i][0],n-v[i][1]);
            v[i][1]=n;            
        }

        vector<int> ans(n,-1);

        l(i,0,n){
            if(v[i][0]<=n){
                if(ans[v[i][0]-1]==-1) ans[v[i][0]-1]=i+1;
            }
        }

        int first_positive_occurance_index=n-1;
        l(i,0,n) if(ans[i]>0){
            first_positive_occurance_index=i;
            break;
        } 

        int minima=n+1;
        l(i,first_positive_occurance_index,n){
            if(ans[i]!=-1)  minima=min(minima,ans[i]);
            ans[i]=minima;
        }
        l(i,0,n) cout<<ans[i]<<" ";
        cout<<endl;
        


    }
}