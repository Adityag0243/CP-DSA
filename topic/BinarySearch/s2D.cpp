#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 
#define rl(i,st,n) for(int i=n-1;i>=st;i--) 
#define srt(v) sort(v.begin(),v.end()) 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vp(v) vector<pair<int,int>> v;

bool check(int n,int arr[][3],int mid,int m){
    int sum=0;
    l(i,0,n){
            int onet=(arr[i][0]*arr[i][1]+arr[i][2]);
            sum+=((mid/onet)*arr[i][1]);
            if(((mid%onet)/arr[i][0])<arr[i][1]){
                sum+= ((mid%onet)/arr[i][0]);
            }else sum+=arr[i][1];
            if(sum>m) break;
    } 
    return (sum>=m);
}


int main(){
    int m,n;
    cin>>m>>n;
    int arr[n][3];
    l(i,0,n){
        l(j,0,3) cin>>arr[i][j];
    }   
    ll low=0;
    ll high=1e9;
    int ans=0;
    
    while(low<=high){
        ll mid=(low+high)/2;
        if(check(n,arr,mid,m)){
            ans=mid;
            high=mid-1;
        }else low=mid+1;
    }
    cout<<ans<<endl;
    vector<int> vans(n);
    int sum=m;
    l(i,0,n){
        int onet=(arr[i][0]*arr[i][1]+arr[i][2]);
        // cout<<((ans/onet)*arr[i][1] + ((ans%onet)/arr[i][0]))<<" ";
        vans[i]=(ans/onet)*arr[i][1];
        sum-=vans[i];
    }
    // cout<<"sum is : "<<sum<<"   ";
    l(i,0,n){
        int onet=(arr[i][0]*arr[i][1]+arr[i][2]);
        // cout<<((ans%onet)/arr[i][0])<<" ";
        if(((ans%onet)/arr[i][0])<sum){
            vans[i]+=((ans%onet)/arr[i][0]); 
            sum-=((ans%onet)/arr[i][0]);
        }else{
            vans[i]+=sum;
            break;
        }
    }
    l(i,0,n) cout<<vans[i]<<" ";
   
}