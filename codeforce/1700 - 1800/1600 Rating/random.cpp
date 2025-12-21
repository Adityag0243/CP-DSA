#include<bits/stdc++.h>
using namespace std;
int n,m;
bool valid(int i, int j){
    return ( i >= 0 && i <n && j >= 0 && j < m);
}

int main(){
    cin >> n >> m;
    vector<vector<int> > v(n, vector<int>(m));
    vector<vector<int> > dp(n, vector<int>(m, 100000));
    for(int i = 0; i <n; i++){
        string s; cin >> s;
        for(int j = 0; j <m; j++){
            v[i][j] = (int)(s[j] - '0');
        }
    }
    dp[0][0] = 0;
    queue< pair<int,int> >q;
    q.push({0,0});
    while( !q.empty() ){
        auto p = q.front(); q.pop();
        int r = p.first;
        int c = p.second;
        int jump = v[r][c];
        int ij[] = {jump, -jump, 0, 0};
        int jj[] = {0, 0, jump, -jump};
        
        for(int i = 0; i < 4; i++){
            if( valid( r+ij[i], c+jj[i] ) ){
                if( dp[r+ij[i]][c+jj[i]] > dp[r][c] + 1){
                    dp[r+ij[i]][c+jj[i]] = 1 + dp[r][c];
                    q.push({r+ij[i], c+jj[i]});
                }
            }
        }        
    }
    // for(int i = 0; i <n ; i++) for(int j = 0 ; j <m ; j++) cout << dp[i][j] << " ";
        
        if(dp[n-1][m-1] == 100000) cout << - 1;
        else cout << dp[n-1][m-1];
    
}