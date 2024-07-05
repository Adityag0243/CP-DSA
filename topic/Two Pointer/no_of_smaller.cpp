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
vector<int> nsmaller(vector<int> &a,vector<int> &b){
    vector<int> c;
    l(i,0,b.size()){
        if(b[i]<=a[0]) c.push_back(0);
        else if(b[i]>a[a.size()-1]) c.push_back(a.size());
        else{
            int num=(upper_bound(a.begin(),a.end(),b[i])-a.begin());
            // cout<<num<<" ";
            if(num==a.size()) num--;
            for(int j=num;j>=0;j--){
                if(a[j]<b[i]){
                    num=j;
                    num++;
                    break;
                }
            }
            
            c.push_back(num);
        }
    }
   
    return c;

}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),c;
    l(i,0,n) cin>>a[i];
    l(i,0,m) cin>>b[i];
    c=nsmaller(a,b);
    l(i,0,c.size()) cout<<c[i]<<" ";
    
}