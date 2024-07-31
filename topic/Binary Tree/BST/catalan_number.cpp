#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll catalan(ll n){
    if(n==0 || n==1) return 1ll*1;
    ll sum=0;
    for(int i=1;i<=n;i++){
        sum+=(catalan(n-i)*catalan(i-1));
    }
    return sum;
}

int main(){
    ll n;
    cin>>n;
    cout<<catalan(n);
}