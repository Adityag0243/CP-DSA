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




int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        l(i,0,n) cin>>a[i];
    

        map<int , int> freq;
        set<int> s;
        for (size_t i = 0; i < n; ++i) {
            s.insert(a[i]);
            int item = a[i];
            freq[item]++;
        }
        vector<int> v;
        for(auto itr=s.begin();itr!=s.end();itr++){
            v.push_back(*itr);
        }
        // vector<pair<int,int>> vfreq;    //frequency first element second
        // for(auto itr=freq.begin();itr!=freq.end();itr++){
        //     vfreq.push_back(make_pair(itr->first,itr->second));
        // }
        int prev=0;
        // vector<int> pre;
        int cnt=0;
        l(i,0,v.size()){
            if(cnt+freq[v[i]]<=i){
                cnt+=freq[v[i]];
                prev=v[i];
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==prev){
                cnt+=(v.size()-1-i);
            }
        }
        cout<<cnt<<endl;
        
        
    }

}
