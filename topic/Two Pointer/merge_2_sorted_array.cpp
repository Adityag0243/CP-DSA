#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++) 


void merge(vector<int> &a,vector<int> &b){     // merge two sorted array
    int pt1=0,pt2=0;
    while(pt1<=a.size() && pt2<=b.size()){   
        if(pt1>=a.size()){
            l(i,pt2,b.size()) cout<<b[i]<<" ";
            pt1=a.size()+1;
            pt2=b.size()+1;
        }else if(pt2>=b.size()){
            l(i,pt1,a.size()) cout<<a[i]<<" ";
            pt1=a.size()+1;
            pt2=b.size()+1;
        }
        else if(a[pt1]>b[pt2]) cout<<b[pt2++]<<" ";
        else cout<<a[pt1++]<<" ";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),c;
    l(i,0,n) cin>>a[i];
    l(i,0,m) cin>>b[i];
    merge(a,b);

}