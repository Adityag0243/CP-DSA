#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl


int main(){
    int t;
    cin>>t;
    vector<int> v(t);
    l(i,0,t) cin>>v[i];

    map<int,int> mp;

    l(i,0,t){
        mp[v[i]]=i;
    }
    string s;
    cin>>s;

    

    vector<int> pre(t-1);
    l(i,0,t-1) pre[i]=(s[i]-'0');
    l(i,1,t-1) pre[i]+=pre[i-1];



    l(i,1,t+1){

        if( mp[i] == i-1  || mp[i] == t-1 ) continue;
        if( mp[i]==0 ){
            if(pre[i-2] != i-1){
                no;
                return 0;
            }
            continue;
        }
        int big   = max( mp[i] , i-1 );
        int small = min( mp[i] , i-1 );
        if(mp[i] < i-1  && s[mp[i]] != '1'){
            no;
            return 0;
        }
        
        if( pre[big-1] - pre[small] != big-small-1  ){
            no;
            return 0;
        }

    }
    yes;
   
}