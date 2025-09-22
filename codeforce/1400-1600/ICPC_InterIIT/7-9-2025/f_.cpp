#include<bits/stdc++.h>
//goel_aadhaar
using namespace std;
//goel_aadhaar
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define int int64_t
#define mod 1000000007

const int MAXN = 200005;
vector<int> father(MAXN);

void init(){
    for(int i = 0; i< MAXN ;++i) father[i] = i;
}
 
int fatherNode(int u){
    
    if( father[u] != u){
        father[u] = fatherNode( father[u] );
    }
    
    return father[u];
}
 
void union_(int u, int v){
    u = fatherNode(u);
    v = fatherNode(v);
    
    father[u] = v;
}
 
// void dfs(int node, vector<int> &vis, vector<vector<pair<int,int>>> &adj, vector<vector<int>> &answer, int &count) {
//     vis[node] = 1;
//     for(auto &p : adj[node]) {
//         int nbr = p.first;
//         int num = p.second;
//         if(!vis[nbr]) {
//             answer.push_back({node + 1, nbr + 1, num});
//             count++;
//             if(count >= vis.size()) return;
//             dfs(nbr, vis, adj, answer, count);
//         }
//     }
// }

int main() {
    init();
    int n;
    cin >> n;

    vector<vector<int>> people(n);
    unordered_map<int, vector<int>> number_to_people;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        people[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> people[i][j];
            number_to_people[people[i][j]].push_back(i);
        }
    }

    vector<vector<pair<int,int>>> adj(n); 
    set<tuple<int,int,int>> used_edges;  

    for (auto &entry : number_to_people) {
        int num = entry.first;
        auto &list = entry.second;

        for (int i = 0; i < list.size(); i++) {
            for (int j = i + 1; j < list.size(); j++) {
                int u = list[i];
                int v = list[j];

                if (used_edges.count({min(u,v), max(u,v), num}) == 0) {
                    adj[u].push_back({v, num});
                    adj[v].push_back({u, num});
                    used_edges.insert({min(u,v), max(u,v), num});
                }
            }
        }
    }

    vector<int> vis(n, 0);
    vector<vector<int>> answer;
    int count = 0;

    dfs(0, vis, adj, answer, count);

    if(count < n - 1) {
        cout << "impossible\n";
    } else {
        for(auto &edge : answer) {
            cout << edge[0] << " " << edge[1] << " " << edge[2] << "\n";
        }
    }

    return 0;
}
