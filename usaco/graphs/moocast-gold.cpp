#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)


vector<int> adj[100005];
bool vis[100005] = {false};


int main(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n;
    cin >> n;
    vector<int> x(n),y(n);
   

    l(i, 0, n){
        cin >> x[i] >> y[i];
    }

    vector<int> min_dist;

    l(i,0,n){
        int ans=INT_MAX;
        l(j,0,n){
            if(i==j) continue;
            int distSq = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            ans = min ( ans , distSq);
        }
        min_dist.push_back(ans);
    }
    cout << *max_element( min_dist.begin() , min_dist.end() );
    
}
