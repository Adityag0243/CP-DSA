#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

// int near(vector<int> &v , int k){
//     // cout<<"k in fn is "<<k<<endl;

//     int ans=v[0];
//     int low=0;
//     int high=v.size()-1;
//     while(low<=high){
//         int mid=(low+high)/2;
//         if(v[mid]<=k){
//             ans=v[mid];
//             low=mid+1;
//         }else high=mid-1;
//     }
//     // cout<<ans<<endl;
//     if(ans==k) return k;
//     int ans2=ans;
//     low=0;
//     high=v.size()-1;
//     while(low<=high){
//         int mid=(low+mid)/2;
//         if(v[mid]>=k){
//             ans2=v[mid];
//             high=mid-1;
//         }else low=mid+1;
//     }
//     // cout<<ans2<<endl;
//     if(abs(ans2-k)>abs(ans-k)){
//         return ans;
//     }
//     else {
//         return ans2;
//     }


// }


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;  
        // cout<<t<<n<<endl;
        vector<int> a(n);
        vector<int> b(n+1);
        set<int> s;


        l(i,0,n){
            cin>>a[i];
            s.insert(a[i]);
        }
        l(i,0,n+1){
            cin>>b[i];
            if(i!=n) s.insert(b[i]);
        } 

        // l(i,0,n) cout<<a[i]<<" ";
        // l(i,0,n+1) cout<<b[i]<<" ";
        // cout<<endl;
        vector<int> v;
        for(auto itr=s.begin();itr!=s.end();itr++){
            v.push_back(*itr);
        }
        // l(i,0,v.size()) cout<<v[i]<<" ";

        // cout<<near(v,b[n])<<endl;
        // int p=near(v,b[n]);
        // cout<<p<<endl;
        ll op=1;
        // op+=(abs(p-b[n]));
        int p=INT_MAX;

        l(i,0,v.size()) p=min(abs(v[i]-b[n]),p);
        l(i,0,n){
            if((b[n]>=a[i] && b[n]<=b[i])  || (b[n]>=b[i] && b[n]<=a[i])){
                p=0;
                break;
            }
        }


        op+=p;
    //    cout<<p<<endl;


        l(i,0,n){
            // cout<<op<<" ";
            op+=(abs(a[i]-b[i]));
        }
        cout<<op<<endl;

    }
}