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
    vector<bool> is_prime(1000001,true);
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<1e6+1;i++){
        if(is_prime[i]==true)
        for(int j=i*i;j<1e6+1;j+=i){
            is_prime[j]=false;
        }
    }

    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        l(i,0,n) cin>>v[i];
        map<int, int> factor_cnt;
        l(i,0,n){
            int a = 2;
            while(v[i]>1){
                if(is_prime[v[i]]){
                    factor_cnt[v[i]]++;
                    v[i]=0;
                }
                else if(v[i]%a==0){
                    factor_cnt[a]++;
                    v[i]/=a;
                }else a++;
                
            }
        }
        bool check=true;
        for (const auto &pair : factor_cnt) {
            if(pair.second % n != 0){
                check=false;
                break;
            }
        }
        if(check) yes;
        else no;
    }
    
}