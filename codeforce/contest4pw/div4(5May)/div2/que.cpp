#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define srt(v) sort(v.begin(),v.end()) 
int binary(int num,vector<int> &v);
int binaryequal(int num,vector<int> &v);


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==0 && m==0){
            cout<<0<<endl;
            continue;
        } 
        if(n==0){
            cout<<
        }
        int prev=pow(2,log2(n))-1;
        if(n-prev<=m) cout<<2*(prev+1)-1<<endl;
        else if((4*(prev+1)-1)-m<=n){
            cout<<4*(prev+1)-1<<endl;
        }else{
            cout<<(prev+1)+(pow(2,1+log2(m+(n-prev))-1))<<endl;
        }
        

    }
}
