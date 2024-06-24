#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;







int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    l(i,0,n){
        cin>>v[i];
    }

    set<string> s;
    s.insert("000");    
    vector<string> vs;

    for(int i=v.size()-1;i>=0;i--){
        if(s.find(v[i])==s.end()) vs.push_back(v[i]);
        s.insert(v[i]);
    }

    l(i,0,vs.size()){
        cout<<vs[i]<<endl;
    }
    
    

  
    
}