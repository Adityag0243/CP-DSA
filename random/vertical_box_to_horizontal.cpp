#include<bits/stdc++.h>
using namespace std;

int main(){

    int dp[10000];
    dp[0] = 0;
    for(int i = 1; i < 10000  ; i++){
        dp[i] = i-1 + dp[i-1];
    }

    int    no_of_box;
    cin >> no_of_box;

    cout<<dp[no_of_box];
}