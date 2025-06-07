#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define   l(i,st,n)    for(int i=st;i<n;i++)
#define   rl(i,st,n)   for(int i=n-1;i>=st;i--)
#define   srt(v)       sort(v.begin(),v.end())
#define   all(a)       (a).begin(),(a).end()





int main(){
    int t;
    cin>>t;
    

    while(t--){
        int a,b;
        cin>>a>>b;
        int diff=abs(b-a);
        if(diff==0){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;;i++){
            ll sum=(i*i+i)/2;
      
            if((diff <= sum) && (diff&1) == (sum&1) ){
                cout<<i<<endl;
                break;
            }
        }
    
        
    }
}