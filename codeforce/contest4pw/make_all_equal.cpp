// https://codeforces.com/contest/2001/problem/0
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
        if((n&1)==0){
            cout<<-1<<endl;
        }else{
            int a=n/2+1;
            l(i,0,n/2+1){
                cout<<a++<<" ";
            }
            a=n/2;
            l(i,0,n/2){
                cout<<a--<<" ";
            }
            cout<<endl;
        }
        
    }
}