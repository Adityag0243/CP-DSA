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
        vector<int> v(3);
        l(i,0,3) cin>>v[i];
        int a=5;
        while(a--){
            srt(v);
            v[0]++;
        }
        cout<<v[0]*v[1]*v[2]<<endl;
        
        
    }
}