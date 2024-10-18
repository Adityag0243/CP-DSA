#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)

vector< pair<int , int >> pos(100005);
vector<int> adj[100005];
bool vis[100005] = {false};


void fn(int i , vector<int> &v){
    // cout<<i<<" : i ,";
    vis[i] = true;
    v[0] = min(v[0] , pos[i].first);
    v[1] = min(v[1] , pos[i].second);
    v[2] = max(v[2] , pos[i].first);
    v[3] = max(v[3] , pos[i].second);
    for(int neighbour : adj[i]){
        if(!vis[neighbour]){
            fn(neighbour , v);
            vis[i] = true;
        }
    }

}

ll peri(int i){
    vector<int> v={INT_MAX , INT_MAX , INT_MIN , INT_MIN };
    fn(i,v);
    // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
    int peri=0;
    peri = 1ll * 2 * ( abs(v[3]-v[1]) + abs(v[2]-v[0]) ) ;
    return peri;
}

int main(){
    freopen("fenceplan.in","r",stdin);
    freopen("fenceplan.out","w",stdout);
    int n,m;
    cin >> n >> m;
   

    l(i, 1, n+1){
        int a,b;
        cin>>a>>b;
        pos[i] = make_pair(a,b);
    }


    l(i, 0, m){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans=INT_MAX;
    l(i,1,n+1){
        if(!vis[i]){
            ans = min( ans , peri(i));
            // cout<<ans<<"<--  ";
        }
    }
    
    cout<<ans;
}
