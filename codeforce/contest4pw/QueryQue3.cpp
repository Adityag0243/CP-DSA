#include <bits/stdc++.h>
using namespace std;
void Scanner(int size,vector<int> &v);
int search(int num,vector<int> &v);

void Scanner(int size,vector<int> &v){
    for(int i=0;i<size;i++){
        cin>>v[i];
    }
}

int search(int num,vector<int> &v){
    int ans=-1;
    int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]>=num) {
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}



int main(){
    
    int n,m;
    cin>>n>>m;
    vector<int> v1(n);
    vector<int>v2(m);
    Scanner(n,v1);
    Scanner(m,v2);
    sort(v1.begin(),v1.end());
   
   
   
    for(int i=0;i<m;i++){
        cout<<search(v2[i],v1)<<" ";
    }
    
    

    
}
    
    