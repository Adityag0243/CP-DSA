#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter length : ";
    cin>>n;
    cout<<"Vector element: ";
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=((n-i)*(i+1)*v[i]);
    }
    cout<<"Sum of all subarray is: "<<sum;
}