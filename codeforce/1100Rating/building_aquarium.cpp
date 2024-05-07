#include <bits/stdc++.h>
using namespace std;

int search_pos(int a,vector<int> &v){
    int pos=0;  //pos :- position index of just less than a value in vector
    int high=n-1;
    low=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]<a){
            pos=mid;
            low=mid+1;
        }else high=mid+1;
    }
    return pos;
}
int search1(int k,vector<int> &v,vector<int> &vnum){
    int high=v[v.size()-1];
    int low=0;
    while(low<=high){
        int mid=(low+high)/2;
        int pos=search_pos(mid,v);
        if((mid*(pos+1)-vnum[pos])==k) return mid;
        else if((mid*(pos+1)-vnum[pos])>k){
            high=mid-1;
        }else low=mid+1;
    }

}


int search2(int k,int high,vector<int> &v,int vnum){
    
    int low=v[v.size()-1]+1;
    while(low<=high){
        int mid=(low+high)/2;

        if((mid*n-vnum)==k) return mid;
        else if((mid*n-vnum)>k){
            high=mid-1;
        }else low=mid+1;
    }

}




int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,x;
        cin>>n>>x;
        
        vector<int> v(n);
        
        for(int j=0;j<n;j++){
            cin>>v[j];
        }
        sort(v.begin(),v.end());
        vector<long long int> vsum(n);
        vsum[0]=v[0];
        for(int j=1;j<n;j++){
            vsum[j]=v[j];
            vsum[j]+=vsum[j-1];
        }
        int ans;

        if((v[n-1]+1)*n-vnum[n-1]==k){
            cout<<v[n-1]+1<<endl;
        }else if((v[n-1]+1)*n-vnum[n-1]<k){
            ans=search1(x,v,vnum);
            cout<<ans<<endl;
        }else{
            int low=v[n-1]+1;
            int high=2*low;
            while(true){
                if(high*n-vnum[n-1]<k){
                    low=high;
                    high*=2;
                }else{
                    break;
                }
            }
            ans=search2(x,high,v,vnum[n-1]);
            cout<<ans<<endl;
        }
        
 

        
        

    }

}