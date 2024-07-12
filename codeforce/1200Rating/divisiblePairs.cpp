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
        int n,x,y;
        cin>>n>>x>>y;
        vector<int> v(n);
        l(i,0,n) cin>>v[i];
        map<pair<int , int> , int> mp;
        ll sum=0;
        l(i,0,n){
            sum+=(mp[make_pair((x-v[i]%x)%x , v[i]%y)]);
            mp[make_pair((v[i]%x)%x , v[i]%y)]++;
        }
        cout<<sum<<endl;
        
    }
}