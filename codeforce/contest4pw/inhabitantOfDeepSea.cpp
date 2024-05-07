#include <iostream>
using namespace std;

int search(int a,vector<int> &v){
    int ans=-1;
    int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]<=a){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    
    
    return ans;
}




int main(){
    int t;
    cin>>t;
    for(int m=0;m<t;m++){
        int n,k;
        cin>>n>>k;
        
        vector<int> v(n);
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        if(sum>=k){
            cout<<n<<endl;
            continue;
        }
        
        vector<int> psum1(n);
        vector<int> psum2(n);
        psum1[0]=v[0];
        for(int i=1;i<n;i++){
            psum1[i]=v[i];
            psum1[i]+=v[i-1];
            cout<<psum1[i]<<" first"<<"  ";
        }
        
        psum2[n-1]=v[n-1];
        for(int i=n-2;i>-1;i--){
            psum2[i]=v[i];
            psum2[i]+=v[i+1];
        }
        
        for(int i=0;i<n;i++){
            cout<<psum1[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            cout<<psum2[i]<<" ";
        }
        cout<<endl;

        sort(psum2.begin(),psum2.end());
        cout<<search(n-n/2,psum1)+2+search(n/2,psum2)<<endl;
    
       

    }
}