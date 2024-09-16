#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define l(i,st,n) for(int i=st;i<n;i++)

vector<int> adj[205];
int vis[205]={0};

void fn(int i,int cnt){
    vis[i]=cnt;
    for(int neighbour : adj[i]){
        if(vis[neighbour] == 0){
            fn(neighbour , cnt);
        }
    }
}

int main(){

    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n;
    cin>>n;
    vector<ll> x(n), y(n), r(n);

    l(i, 0, n){
        cin >> x[i] >> y[i] >> r[i];
    }
    
    l(i,0,n){
        l(j,0,n){
                if(i != j){
                ll distSq = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if(r[i] * r[i] >= distSq){  // Can cow i communicate with cow j?
                    adj[i].push_back(j);
                }
            }

        }
    }

    int cnt=0;
    l(i,0,n){
        if(vis[i]==0){
            cnt++;
            fn(i,cnt);
        }
    }
    vector<int> freq(cnt + 1, 0);  // component frequency array
    l(i, 0, n){
        freq[vis[i]]++;
    }
    
    cout << *max_element(freq.begin(), freq.end());
}