#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             int64_t
#define yes             cout << "YES" << endl;
#define no              cout << "NO" << endl;
#define p(x)            cout << (x) << endl;
#define sp(x)           cout << (x) << " ";
#define endl            '\n'
#define pb              push_back
#define mxv(arr)        *max_element(arr.begin(), arr.end())
#define mnv(arr)        *min_element(arr.begin(), arr.end())
#define smv(arr)        accumulate(arr.begin(), arr.end(), 0LL)
#define srt(arr)        sort(arr.begin(), arr.end())
#define rev(arr)        reverse(all(arr))
#define MOD2            1000000007
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// vector<int> l1;

class DSU{
public:
    vector<int> parent;
    vector<int> exp;


    DSU(int n){
        parent.resize(n+1);
        exp.resize(n+1, 0);
        l(i,0,n+1) parent[i] = i;
    }
    

    int find(int x){
        if( parent[x] != x){
            int par = parent[x];
            parent[x] = find( parent[x] );
            // will add except the root's exp bcz of get_() logic....
            if(parent[par] != par) exp[x] += exp[par];
        }
        return parent[x];
        
    }

    void join(int x, int y)
    {
        x = find(x);
        y = find(y);

        if( x == y) return;

        exp[y] -= exp[x];
        parent[y] = x;
    }

    void add(int x, int v){
        exp[ find(x) ] += v;
    }

    int get_(int x){
        
        if( parent[x] == x) return exp[x];
        find(x);

        int total = 0;
        total += exp[x];
        //  I guess after find(x) x is attached directly to root....
        total += parent[x];

        return total;
    } 
};


signed main(){
    fastio
    int n,m; cin >> n >> m;
    
    DSU* dsu = new DSU(n);

    while(m--){
        string type;
        cin >> type;

        if( type == "add"){

            int x,v; cin>>x >>v;
            dsu->add(x,v);

        }else if( type == "join" ){

            int x,y; cin >> x >> y;
            dsu->join(x,y);

        }else{

            int x; cin >> x;
            cout << dsu->get_(x) << endl;

        }
    }
    return 0;
}