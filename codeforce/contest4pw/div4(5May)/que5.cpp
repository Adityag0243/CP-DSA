#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
#define loop(i,st,n) for(int i=st;i<n;i++) 
#define srt(v) sort(v.begin(),v.end()) 
int binary(int num,vector<int> &v);
int binaryequal(int num,vector<int> &v);



int binary(int num,vector<int> &v){
    int ans=0;
    int low=0;
    int high=v.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]<num){
            ans=mid;
            low=mid+1;
        }else high=mid-1;
    }
    return ans;
}

int binaryequal(int num,vector<int> &v){
    int ans=-1;
    int low=0;
    int high=v.size();
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]==num) {
            ans=mid;
            break;
        }
        if(v[mid]<num){
            low=mid+1;
        }else high=mid-1;
    }
    return ans;
}


int main(){
	
	int t;
	cin>>t;
	while(t--){
	    int n,k,q;
        cin >>n>>k>>q;
        vector<int> va(k+1);
        vector<int> vb(k+1);
        va[0]=0;
        vb[0]=0;
        loop(i,1,k+1) cin>>va[i];
        loop(i,1,k+1) cin>>vb[i];
        while(q--){
            int d;
            cin>>d;
            int pos;
            if(binaryequal(d,va)!=(-1)){
                pos=binaryequal(d,va);
                cout<<vb[pos]<<" ";
                continue;
            }
            pos=binary(d,va);
            long double ans=vb[pos];
            long double speed=(long double)(va[pos+1]-va[pos])/(vb[pos+1]-vb[pos]);
            ans+=((long double)(d-va[pos])/speed);
            cout << fixed << setprecision(0) << ans << " ";
            
        }
        cout<<endl;
        
	}
}