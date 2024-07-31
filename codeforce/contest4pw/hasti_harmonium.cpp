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
    string s;
    cin>>s;
    char ch=s[0];
    
    l(i,0,s.size()-1){
       ch=min(ch,s[i]);
    }
    int ind;
    l(i,0,s.size()){
        if(s[i]==ch){
            ind=i;
            break;
        }
    }
    char ch2='z';

    l(i,ind+1,s.size()){
        ch2=min(ch2,s[i]);
    }
    cout<<ch<<ch2;

}