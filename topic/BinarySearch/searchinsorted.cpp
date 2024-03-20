// -4 0 1 5 8 11 19 23 45 76 98 120 127 132 find 11 in this array 

#include <bits/stdc++.h>
using namespace std;

int search(int num,vector<int> &v){
    int ans=-1;
    int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid]>num) high=mid-1;
        else if(v[mid]<num) low=mid+1;
        else {
            ans=mid;
            break;
        }
    }
    return ans;
}

int main(){
    vector<int> v={-4,0,1, 5, 8, 11, 19, 23, 45, 76, 98, 120, 127, 132};
    int n;
    cout<<"Enter the number you want to search: ";
    cin>>n;
    
    if(search(n,v)==-1){
        cout<<"This number is not in array.";
    }
    else cout<<search(n,v);
}