// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
// How many perfect square factors does the number 46,656 have?
int main() {
    int n=46656;
    vector<int> v;
    for(int i=2;i*i<=n;i++){
        int cnt=0;
        bool check=false;
        while(n%i==0){
            cout<<i<<" ";
            cnt++;
            n/=i;
        }
        if(cnt>1) v.push_back(1+(cnt/2));
    }
    int ans=1;
    for(int i=0;i<v.size();i++){
        ans*=v[i];
    }
    cout<<ans;
    
    

    return 0;
}