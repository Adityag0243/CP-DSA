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
        string s;
        cin>>s;
        vector<int> v(26,0);
        l(i,0,n) v[s[i]-'a']++;
        // srt(v);
        l(m,0,26){
            bool check=true;
            l(i,0,26){
                if(v[i]!=0) check=false;
            }
            if(check) break;


            int max_ind=0,sec_max_ind=0;
            l(i,1,26){
                if( v[i]>=v[max_ind] ) {
                    max_ind=i;
                }
            }
            l(i,1,26){
                if(i!=max_ind && v[i]>=v[sec_max_ind] ) {
                    sec_max_ind=i;
                }
            }

            // cout<<char('a'+max_ind)<<char('a'+sec_max_ind)<<endl;


            while(v[sec_max_ind]>0){
                cout<<char('a'+max_ind)<<char('a'+sec_max_ind);
                v[sec_max_ind]--;
                v[max_ind]--;
            }

            
            
        }
        l(i,0,26){
            while(v[i]>0){
                cout<<char('a'+i);
                v[i]--;
            }
        }
        cout<<endl;

       
        
    }
}