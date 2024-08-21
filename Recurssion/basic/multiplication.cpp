#include<bits/stdc++.h>
using namespace std;

// a*b without *

int multi(int a,int b){
    if(a>b) swap(a,b);
    if(b==0) return 0;
    if(b<0) return multi(a,b+1)-a;
    return multi(a,b-1)+a;
}

int main(){
    cout<<multi(-7,-4);
}