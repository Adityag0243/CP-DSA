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

bool valid(int i,int j,int n,int m){
    if(i<0 || j<0) return false;
    if(i>=n) return false;
    if(j>=m) return false;
    return true;
}



int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(n<=2){
            cout<<stoi(s)<<endl;
            continue;
        }
        bool flag=false;
        l(i,0,n){
            if(s[i]=='0'){
                cout<<0<<endl;
                flag=true;
                break;
            }

            else if(s[n-1]==1 && s[n-2]=='1'){
                bool check=false;
                l(i,0,n-3){
                    if(s[i]==s[i+1] && s[i]=='1'){
                        check=true;
                        break;
                    }
                }
                flag=!check;
                if(check==false){
                    ll ans=11;
                    l(i,0,n-2){
                        if(s[i]!='1') ans+=(s[i]-'0');
                    }
                    cout<<ans<<endl;
                    break;
                }
                
            }

        }
        if(flag) continue;

        bool check=true;
        l(i,0,n){
            if(s[i]!='1'){
                check=false;
                break;
            }
        }
        if(check){
            cout<<11<<endl;
            continue;
        }


            
            ll ans=0;
            if(s[0]!='1') ans=s[0];
            int cnt=1;
            // vector<int> vnum;
            l(i,1,n){
                if(s[i]=='1') continue;
                if(cnt && i>1 && s[i-1]=='1' && s[i-2]=='1'){
                    ans+=(10+(s[i]-'0'));
                    cnt=0;
                }else ans+=(s[i]-'0');

            }
            cout<<ans<<endl;

        }
    
   
        
  

}
