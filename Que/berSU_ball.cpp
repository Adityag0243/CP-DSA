#include <bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    vector<int> v1;
    for(int i=0;i<t;i++){
        int a;
        cin>>a;
        v1.push_back(a);
    }
    
    int k;
    cin>>k;
    vector<int> v2;
    for(int i=0;i<k;i++){
        int a;
        cin>>a;
        v2.push_back(a);
    }
    
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    
    int count=0;
    if(v1[t-1]+1<v2[0]){
        count=0;
        cout<<0;
        return 0;
    }
    int j=0;
    for(int i=0;i<t;i++){
        for(;j<k;j++){
            int a=v1[i];
            int b=v2[j];
            if(b>a+1) break;
            //cout<<a<<b<<" ";
            if(a==b||a==b+1||a==b-1){
                count++;
                j++; // it is important agar yaha j nhi increase krenge to j pichhe ataka pada rhega
                //kyuki break ho rha hai jabardasti isme aane ke baad loop wrna khud se jab hot ahia to j apne aap ek badh jata hai loop ki 3rd arguments se 
                break;
            }
        }
        //cout<<"j is "<<j<<" ";

    }
    cout<<count;
    
}
