//-4,0,1,5,8,98,98,98,98,120,127,132 want to insert 98 ab kae option hai to first aur last options batana hai i.e 5 and9 index

#include <bits/stdc++.h>
using namespace std;

//**********************************************

vector<int> searchRange(vector<int>& v, int target) {
    

        vector<int> ans={-1,-1};
        //cout<<ans[0]<<ans[1];
        int low=0;
        int high=v.size()-1;
        int check=0;
        
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]<target){
                low=mid+1;
            }else if(v[mid]>target) {
                high=mid-1;
            }else{
                check=1;
                break;
            }
        }
        if(check==0){
            return ans;
        }
        low=0;
        high=v.size()-1;
        if(target==v[0]) ans[0]=0;
        else{
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]<target){
                ans[0]=mid+1;
                low=mid+1;
            }else {
                high=mid-1;
            }
        }
        }
        if(target==v[v.size()-1]) ans[1]=v.size()-1;
        else{
        low=0;
        high=v.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(v[mid]>target){
                ans[1]=mid-1;
                high=mid-1;                
            }else {                
                low=mid+1;
            }
        }
        }
        return ans;
    }

//*******************************************

int main(){
    vector<int> v={-4,0,1,8,8,98,98,98,132,132,132};
    int n;
    cout<<"Enter the number you want to insert: ";
    cin>>n;
    vector<int> a=searchRange(v,n);
    cout<<a[0]<<" "<<a[1];

    
}
