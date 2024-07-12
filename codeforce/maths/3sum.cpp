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
        l(i,0,n) v[i]%=10;

        vector<int> smart;
        for(int i=0;i<10;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(v[j]==i) count++;
                if(count==3) break;
            }
            while(count--){
                smart.push_back(i);
            }

        }
        bool flag=false;
        int len=smart.size();
        for(int i=0;i<len-2;i++){
            for(int j=i+1;j<len-1;j++){
                for(int k=j+1;k<len;k++){
                    if((smart[i]+smart[j]+smart[k])%10==3){
                        flag=true;
                        break;
                    }
                }
                if(flag) break;
            }
            if(flag) break;
        }
        if(flag) yes;
        else no;
        
    }
}