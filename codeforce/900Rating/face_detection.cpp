#include <bits/stdc++.h>
using namespace std;


int main(){
    
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        int count=0;
        for(int i=a;i<=x;i++){
            for(int j=b;j<min(i,y+1);j++){
                count++;
            }
        }
        cout<<count<<endl;
        // for(int i=a;i<=x;i++){
        //     for(int j=b;j<=i;j++){
        //         cout<<i<<" "<<j<<endl;
        //     }
        // }

        for(int i=a;i<=x;i++){
            for(int j=b;j<min(i,y+1);j++){
                cout<<i<<" "<<j<<endl;
            }
        }
        



}