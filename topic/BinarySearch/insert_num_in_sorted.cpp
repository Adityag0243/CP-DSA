// -4,0,1,5,8,98,120,127,132  find index where we can insert any number n like n=2 at 3, 100 at 6 after 98

#include <bits/stdc++.h>
using namespace std;

//**********************************************

int insert(int num,vector<int> &v){
    int ans;
    int low=0;
    int high=v.size()-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>=num){
            ans=mid;
            high=mid-1;
        } 
        else low=mid+1;
    }
    return ans;
}

//*******************************************

int main(){
    vector<int> v={-4,0,1,5,8,98,120,127,132,176,56,42,10,9,2};
    int n;
    cout<<"Enter the number you want to insert: ";
    cin>>n;
    cout<<insert(n,v);

    
}