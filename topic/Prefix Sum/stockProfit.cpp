// A=[7,1,3,5,6,4]   find max profit for first buying stock and then sell
// pura sahi nhi hai

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter length : ";
    cin>>n;
    vector<int> v(n);
    cout<<"Vector element: ";
    for(int i=0;i<n;i++) cin>>v[i];

    for(int i=1;i<n;i++){
        v[i]-=v[0];

    }

    // prefix max
    // int max=v[0];
    // vector<int> vmax(n);
    // vmax[0]=v[0];
    // for(int i=n-1;i>0;i++){
    //     if(v[i]>max){
    //         vmax[i]=v[i];
    //         max=v[i];
    //     }
    // }

    // for(int i=0;i<n-1;i++){
    //     v[i]=vmax[n-1]-v[i];
    // }
    sort(v.begin()+1,v.end());
    if((v[n-1]-v[0])<0) cout<<0<<" ok ";
    else cout<<v[n-1]-v[0];

    // now find maximum value of updated v
    // if it is negative then print zero

}


