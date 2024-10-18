#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define srt(v) sort(v.begin(),v.end())
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
 
 
int main(){
 
    fastio
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    vector<int> cnt(mxv(v)+1,0);
 
    l(i,0,n){
        for(int j = 1; j*j <= v[i] ; j++){
            if(v[i]%j==0){
                cnt[j]++;
                if(j*j != v[i]) cnt[v[i]/j]++;
            }
        }       
    }
    rl(i,1,mxv(v)+1){
        if(cnt[i] > 1 ){
            cout<< i;
            return 0;
        }
    }
    cout<<1;
}
    