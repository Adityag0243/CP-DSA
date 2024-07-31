#include<bits/stdc++.h>     // not solved
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
        vector<int> val(2*n-1,0);

        l(i,0,n){
            val[v[i]-1]=i+1;
        }
        int cnt=0;
        l(i,3,2*n){
            for(int j=1;j*j<i;j++){
                if(i%j==0){
                    if(val[j-1]!=0 && val[i/j -1]!=0 && (val[j-1]+val[i/j -1])==i) cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        

        
    }
}