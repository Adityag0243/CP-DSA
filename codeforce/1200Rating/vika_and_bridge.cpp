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

        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        l(i,0,n) cin>>v[i];
        vector<int> pos[n];

        l(i,0,n) pos[i].push_back(-1);
        l(i,0,n){
            pos[v[i]-1].push_back(i);
        }
        l(i,0,n) pos[i].push_back(n);

        vector<int> dist[n];
        l(i,0,n){
            l(j,1,pos[i].size()) dist[i].push_back(pos[i][j]-pos[i][j-1]-1);
        }

        l(i,0,n) srt(dist[i]);
        vector<int> ans(n);
        l(i,0,n){
            dist[i].size()==1 ? ans[i]=n/2 : ans[i]=max(dist[i][dist[i].size()-1]/2,dist[i][dist[i].size()-2]); 
        }

        cout<<*min_element(ans.begin(),ans.end())<<endl;
    }
}