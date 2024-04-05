#include <bits/stdc++.h>
using namespace std;



int main(){

    int n=4200;
    int num=n;
    for(int i=2;i<=num && n>0;){
        if(n%i==0){
            cout<<i;
            n/=i;
        }
        else i++;
    }
}