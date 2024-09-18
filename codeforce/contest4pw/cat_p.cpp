#include<bits/stdc++.h>
using namespace std;

#define l(i,st,n) for(int i=st;i<n;i++)


int n,m;
int present[100005]={0};
vector<int> adj[100005];


int fn(int node , int cat){

    int ans=0;

    if( cat > m) return 0;
    if( adj[node].size()==0 && cat <= m ) return 1;

    for( auto neighbour : adj[node] ){ 
        if(present[neighbour]==0) ans += fn(neighbour , 0);
        else{
            if(cat < m) ans += fn(neighbour , cat+present[neighbour]);
        }
    }
    return ans;
}



int main(){

    cin>>n>>m;

    l(i,1,n+1) cin>>present[i];


    l(i,0,n-1){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    
    cout<<fn(1,present[1]);
   
}