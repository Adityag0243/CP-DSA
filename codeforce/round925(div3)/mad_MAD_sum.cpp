#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// #define ll int
#define l(i,st,n) for(int i=st;i<n;i++)
#define srt(v) sort(v.begin(),v.end())


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v,v2;
        set<int> s;
        int val=0;
        ll sum=0;

        l(i,0,n){
            int a;
            cin>>a;
            sum+=a;
            if(a>val){
                if(s.find(a)==s.end()) s.insert(a);
                else val=a;
                v.push_back(val);
            }else{
                if(s.find(a)==s.end()) s.insert(a);
                v.push_back(val);
            }
        }
        set<int> s2;
        val=0;

        // after 1st time there may case exist like  0 0 1 2 --> 0 0 0 0 or something like..
        // 0 0 0 2 2 3 4 -->which leads to 0 0 0 0 2 2 2 to handle this doing same thing again
        // now for sure this will leads to a series where only end may get single different value other value must be in pair atleast

        l(i,0,n){
            int a=v[i];
            sum+=a;
            if(a>val){
                if(s2.find(a)==s2.end()) s2.insert(a);
                else val=a;
                v2.push_back(val);
            }else{
                if(s2.find(a)==s2.end()) s2.insert(a);
                v2.push_back(val);
            }
        }


        l(i,1,n){
            sum+=(1ll*v2[i]*(n-i));
        }
        cout<<sum<<endl;
        
        
    }
}