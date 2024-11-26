#include<bits/stdc++.h>
using namespace std;
#define l(i,st,n) for(int i=st;i<n;i++)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl

int n;
vector<int> v(100005);

class DSU {
private:
    std::vector<int> parent; // Parent of each element
    std::vector<int> rank;   // Rank (or depth) of each set
    std::vector<int> siz;    // Size of each set

public:

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1); 
        siz.resize(n, 1);  
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    // Union function by rank, updating size
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
                siz[rootX] += siz[rootY]; // Update size of the new root
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
                siz[rootY] += siz[rootX]; // Update size of the new root
            } else {
                parent[rootY] = rootX;
                siz[rootX] += siz[rootY]; // Update size of the new root
                rank[rootX]++;
            }
        }
    }

    // Check if two elements belong to the same set
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // Get the size of the set containing element x
    int getSize(int x) {
        return siz[find(x)];
    }
};

int main(){
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(0); // Untie cin from cout
    cin >> n ;
    
    l(i,0,n) cin>>v[i];

    DSU d(n);

    l(i,0,n){    
        if(v[i] == 0) continue;
        else{
            d.unite(i,v[i]-1);
        }
    }
    int a=0,b=0;
    for(int i = 0; i<n ; i++){
        if(v[i] == 0 && d.getSize(i) > b){
            a= i+1;
            b= d.getSize(i);
        }
    }
    cout<<a<<" "<<b;
}
