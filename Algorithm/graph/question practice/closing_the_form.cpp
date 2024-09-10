#include <bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
#define rl(i,st,n) for(int i=n-1;i>=st;i--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int n, m;
vector<vector<int>> adjList;  // Adjacency list
int cnt = 1;
set<int> skip;

void dfs(int i, vector<int>& vis) {
    vis[i] = 1;
    cnt--;
    for (int neighbor : adjList[i]) {
        if (!vis[neighbor] && skip.find(neighbor) == skip.end()) {
            dfs(neighbor, vis);
        }
    }
}

int main() {
    // Redirect standard input and output to files
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    cin >> n >> m;
    adjList.resize(n + 1);  // Initialize adjacency list

    set<int> s;
    l(i, 1, n + 1) s.insert(i);

    l(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);  // Add edge to adjacency list
        adjList[b].push_back(a);  // Add edge to adjacency list
    }

    rl(t, 1, n + 1) {
        cnt = t;
        vector<int> vis(n + 1, 0);
        int node;
        cin >> node;

        dfs(*s.begin(), vis);  // Start DFS from the first available node in the set
        s.erase(node);

        if (cnt == 0) yes;
        else no;

        skip.insert(node);  // Mark the node as removed
    }

    return 0;
}
