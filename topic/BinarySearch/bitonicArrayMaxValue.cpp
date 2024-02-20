// -4,0,1,5,8,98,120,127,******132*****,76,56,42,10 find highest value in this array all value are distinct

#include <bits/stdc++.h>
using namespace std;

int maxVal(vector<int> &v){
    int low=0;
    int high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>v[mid-1]&&v[mid]>v[mid+1]) return v[mid];

        if(v[mid]>v[mid-1]) low=mid+1;
        else if(v[mid]<v[mid-1]) high=mid-1;
        
    }
}

int main(){
    vector<int> v={-4,0,1,5,8,98,120,127,132,176,56,42,10,9,2};
    cout<<"max value is: " <<maxVal(v);
    
}