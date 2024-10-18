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
#define x               first
#define y               second
#define gcd(a,b)        __gcd((a),(b))
#define lcm(a,b)        ((a)*(b)) / gcd((a),(b))
#define l(i,st,n)       for(int i=st;i<n;i++)
#define rl(i,st,n)      for(int i=n-1;i>=st;i--)
#define fastio          ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 
 
 
int n;
vector<int> sg_tree;
 
 
int range_sum(int root, int node_left , int node_right ,int query_low , int query_high){
 
    if( query_low > node_right) return 0;
    if( query_high < node_left) return 0;
    if( query_high >= node_right && node_left >= query_low) return sg_tree[root];
    return ( range_sum( 2*root,node_left , (node_left + node_right)/2, query_low, query_high )
            ^ range_sum(2*root+1, (node_left + node_right)/2 +1 , node_right, query_low, query_high) );
}
 
 
 
 
signed main(){
    int q;
    cin >> n >> q;
    vi v(n);
    l(i,0,n) cin >> v[i];
    while(__builtin_popcount(n) != 1){   // to make n power of two // __builtin_popcount(val) tell no of 1 in the binary bit of val
        v.push_back(0);
        n++;
    }
 
    sg_tree.resize(2*n);
 
    // pushing v vector in last of segment tree vector
    l(i,n,2*n){
        sg_tree[i] = v[i-n]; 
    }
    // pushing sum of nodes to their parents reversely , why ?
    rl(i,0,n){
        sg_tree[i] = (sg_tree[2*i] ^ sg_tree[2*i + 1]);
    }
    
    while(q--){
        int a , b;
        cin >> a >> b;
        a--;
        b--;
        cout << range_sum(1 , 0 , n-1 , a , b) << endl;
        
    }
}