#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++) 

void merge(vector<int> &v,int st,int mid,int end){     // merge two sorted array
    vector<int> c;
    int len1=mid-st+1;
    while(pt1<=a.size() && pt2<=b.size()){
        if(pt1>=a.size()){
            l(i,pt2,b.size()) c.push_back(b[i]);
            pt1=a.size()+1;
            pt2=b.size()+1;
        }else if(pt2>=b.size()){
            l(i,pt1,a.size()) c.push_back(a[i]);
            pt1=a.size()+1;
            pt2=b.size()+1;
        }
        else if(a[pt1]>b[pt2]) c.push_back(b[pt2++]);
        else c.push_back(a[pt1++]);
    }

    return c;
}

vector<int> mergesort(vector<int> &v,int st,int end){
    if(st>=end) return;

    int mid=(st+end)/2;
    mergesort(v,st,mid);
    mergesort(v,mid+1,end);
    merge(v,st,mid,end);
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    l(i,0,n) cin>>v[i];
    mergesort(v,0,n-1);
    l(i,0,n) cout<<v[i]<<" ";
}