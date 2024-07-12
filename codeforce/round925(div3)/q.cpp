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
        int n,m,k;
        cin>>n>>m>>k;
        vector<char> v(n);
        l(i,0,n) cin>>v[i];
        int i=0;
        bool ans=true;
        while(i<n){
            bool check=true;
            int stop=m;
            while(stop-- && i<n ){
                if(v[i]=='L'){
                    check=false;
                    i++;
                    break;
                }
                i++;
                
            }
            if(stop>0 && i<=n && v[i-1]!='L'){
                check=false;
            }
            if(check){
                if(v[i]=='C'){
                    ans=false;
                    break;
                }else{
                    while(v[i]!='L'){
                        k--;
                        if(v[i]=='C' || k<0){
                            ans=false;
                            break;
                        }
                        i++;
                    }
                    if(ans==false) break;
                    i++;
                }
            }
        }
        if(ans==false) no;
        else yes;
        

        
    }
}