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
        vector<int> v(n);
        l(i,0,n) cin>>v[i];

        bool all=true;
        l(i,0,n){
            if(v[i]!=0) all=false;
        }
        if(all){
            l(i,1,n+1) cout<<i<<" ";
            continue;
        }

        vector<int> bit(32,0);
        l(i,0,n){
            l(j,0,31){
                if((v[i]>>j) & 1) bit[j]++;
            }
        }
        int maxi = *max_element(bit.begin(),bit.end());
        l(i,1,maxi+1){
            bool check = true;
            l(j,0,bit.size()){
                if(bit[j] % i ) check = false;
            }
            if(check) cout<<i<<" ";
        }
        cout<<endl;
        
    }
}