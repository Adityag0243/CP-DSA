#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define rloop(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
int main(){
  int n;
  cin>>n;
 
  vector<pair<string,int>> v;
  int sum=0;
  loop(i,0,n){
    string s;
    cin>>s;
    int sc;
    cin>>sc;
    sum+=sc;
    v.push_back(make_pair(s,sc));
  }
  srt(v);
  sum%=n;
  cout<<v[sum].first;

}