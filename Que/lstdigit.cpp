#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        long long int a,b,c;
        cin>>a>>b>>c;

        cout>>((a%10)+(b%10)+(c%10))%10;
    }
}