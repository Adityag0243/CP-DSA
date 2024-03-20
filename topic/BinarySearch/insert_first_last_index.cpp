//-4,0,1,5,8,98,98,98,98,120,127,132 want to insert 98 ab kae option hai to first aur last options batana hai i.e 5 and9 index

#include <bits/stdc++.h>
using namespace std;

//**********************************************

int insert(int num,vector<int> &v){
    int ans1,ans2;
    int low=0;
    int high=v.size()-1;

    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>=num){         // yaha equal lagane se first wala dega why?? think about it
            ans1=mid;
            high=mid-1;
        } 
        else low=mid+1;
    }
    low=0;
    high=v.size()-1;
    while(low<=high){
        int mid=(low+high)/2;

        if(v[mid]>num){             //bus yaha se equal to hata dia ab last wala index dega
            ans2=mid;
            high=mid-1;
        } 
        else low=mid+1;
    }


    int ans=10*ans1+ans2;          //for indices 5 and 9 it will return 59 for 2 and 4 it will return 24  
    return ans;            // waise ye galat hai if ans1 = 12 and ans2=15 
}

//*******************************************

int main(){
    vector<int> v={-4,0,1,5,8,98,98,98,132,176,256};
    int n;
    cout<<"Enter the number you want to insert: ";
    cin>>n;
    cout<<insert(n,v)/10<<" and "<<insert(n,v)%10;   //as it return 5 and 9 as 59

    
}
