// https://cses.fi/problemset/task/1081/
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
    vector<bool> is_prime(1000001,true);
    vector<int> prime;
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i*i<1e6+1;i++){
        prime.push_back(i);
        if(is_prime[i]==true)
        for(int j=i*i;j<1e6+1;j+=i){
            is_prime[j]=false;
        }
    }

    
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    set<int> s;
    s.insert(1);
    l(i,0,n){
        s.insert(v[i]);
        if(is_prime[v[i]]==false){
            for(int j=2;j*j<=v[i];j++){
                if(v[i]%j==0){
                    s.insert(j);
                    s.insert(v[i]/j);
                }
            }
        }
    }
    vector<int> possible;
    for(auto it=s.begin();it!=s.end();it++){
        possible.push_back(*it);
    }
    
    rl(i,0,possible.size()){
        cout<<possible[i]<<" ";
        int cnt=0;
        bool check = false;
        l(j,0,n){
            if(v[j]%possible[i]==0) cnt++;
            if(cnt==2){
                check=true;
                break;
            }
        }
        if(check){
            cout<<possible[i];
            break;
        }
        
    }
        
    
}