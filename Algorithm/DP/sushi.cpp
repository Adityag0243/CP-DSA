#include<bits/stdc++.h>
using namespace std;

int n;
// double dp[10][10][10];
// double fn(int a,int b,int c){
//     if(a<0 || b<0 || c<0 || a+b+c ==0) return 0;
//     cout<<"hmm  ";
//     int total = 0;
//     if(a) total++;
//     if(b) total++;
//     if(c) total++;
//     if(a+b+c != n) total++;

//     if(dp[a][b][c] != -1) return dp[a][b][c];
//     double ans = 0;
//     if(a) ans += ((a/total) + fn(a-1,b,c));
//     if(b) ans += ((b/total) + fn(a,b-1,c));
//     if(c) ans += ((c/total) + fn(a,b,c-1));
//     if(a+b+c != n && a+b+c != 0)  ans += ((n-a-b-c)/total ); 
//     return dp[a][b][c] = ans;

// }



int main(){

    cin >> n;
    int a=0,b=0,c=0;
    for(int i =0 ; i < n ;i++){
        int num;
        cin>>num;
        if(num==1) a++;
        else if(num==2) b++;
        else if(num==3) c++;
    } 
    float dp[n+1][n+1][n+1];
    memset(dp,0, sizeof(dp));
    // cout<<fn(a,b,c);

    for(int i = 0 ; i < n ; i++){
        for(int  j = 0 ; j < n ;j++){
            for(int k = 0 ; k < n; k++){
                dp[i+1][j][k] = 1 + dp[i][j][k] ;
                dp[i][j+1][k] = 1 + dp[i][j][k] ;
                dp[i][j][k+1] = 1 + dp[i][j][k] ;
            }
        }
    }
    cout<<dp[a][b][c];


}