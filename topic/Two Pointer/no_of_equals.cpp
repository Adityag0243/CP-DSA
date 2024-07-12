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
// ll equals(vector<int> &a,vector<int> &b){
//     ll total=0;                                       // using binary search algorithm
//     l(i,0,b.size()){
//         int l=lower_bound(a.begin(),a.end(),b[i])-a.begin();
//         int r=upper_bound(a.begin(),a.end(),b[i])-a.begin();
//         cout<<r-l<<" ";
//         total+=(r-l);
//     }
//     return total;
// }


ll equals(vector<int> &a,vector<int> &b){
    ll count=0;
    int pt1=0;
    int j=0;
    
    l(i,0,b.size()){
        if(b[i]<a[0] || b[i]>a[a.size()-1]) continue;
        bool check=false;
        for(;j<a.size();j++){
            if(a[j]==b[i]){
                pt1=j;
                break;
            }else if(a[j]>b[i]){
                pt1=j;
                check=true;
                break;
            }
        }
        if(check) continue;
        for(;j<a.size();j++){
            if(a[j]>b[i]){
                count+=(j-pt1);
                while(b[i+1]==b[i]){
                    count+=(j-pt1);
                    i++;
                }
                j--;
                check=true;
                break;
            }
        }
        if(check) continue;
        if(b[i]==a[a.size()-1]){
            count+=(j-pt1);
        }

    }
    return count;
}






int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    l(i,0,n) cin>>a[i];
    l(i,0,m) cin>>b[i];

    cout<<equals(a,b);
}