#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v(32769,16);



int f(int num) {
    queue<pair<int,int>> q;
    q.push(make_pair(num,0));
    bool vis[32769]={false};
    vis[num]=true;

    while(!q.empty()){

        int val =   q.front().first;
        int cnt =   q.front().second;
        q.pop();

        if(val==0 || val==32768){
            v[num]=cnt;
            return cnt;
        }

        if(!vis[val+1]){
            q.push(make_pair(val+1,cnt+1));
            vis[val+1]=true;
        }
        if(!vis[(2*val)%32768]){
            q.push(make_pair((2*val)%32768,cnt+1));
            vis[(2*val)%32768]=true;
        }

    }
   return 15;
}

int main() {
    int t;
    cin >> t;


    while (t--) {
        int n;
        cin >> n;
        if(v[n]<16) cout<<v[n]<<endl;
        else cout << f(n) <<endl;
    }
}
