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
 
 
int range_max(int root, int node_left, int node_right, int query_low, int query_high) {
    // Case 1: No overlap
    if (query_high < node_left || query_low > node_right)
        return INT_MIN;

    // Case 2: Complete overlap
    if (query_low <= node_left && node_right <= query_high)
        return sg_tree[root];

    // Case 3: Partial overlap
    int mid = (node_left + node_right) / 2;
    return max(
        range_max(2 * root, node_left, mid, query_low, query_high),
        range_max(2 * root + 1, mid + 1, node_right, query_low, query_high)
    );
}

 
 
 
 
void fn(){

    int c;
    cin >> n >> c;
    int sz = n;

    vi h(n);
    l(i,0,n) cin >> h[i];  // height wala...
    l(i,1,n) h[i] += h[i-1];

    vi v(n);  // v is my strength array...
    l(i,0,n) cin >> v[i];
    // for(int x : h) cout << x  << ' ';
    // cout << endl;
    // for(int x : v) cout << x  << ' ';


    while(__builtin_popcount(n) != 1){  
        v.push_back(0);
        n++;
    }
 
    sg_tree.resize(2*n);   

    l(i,n,2*n){
        sg_tree[i] = v[i-n]; 
    }
    rl(i,0,n){
        sg_tree[i] = min(sg_tree[2*i] , sg_tree[2*i + 1]);
    }
    

    int lo = 0;
    int hi = sz;
    int ans = 0;

    while( lo <= hi )  {

        int mid = (lo + hi)/2;

        for(int i = 0; i+mid <= sz; i++){
            int hsum = h[i+mid-1];
            if( i > 0) hsum -= h[i-1];
            hsum *= mid;

            int maxi = range_max(1 , 0 , n-1 , i , i+mid-1);
            
            
            cout << i << " " << i+mid << " : range ans : "<< maxi << "\n";
            if( c >= maxi + hsum){
                ans = mid;
                lo = mid+1;
            }else{
                hi = mid-1;
            }
        }
    }

    cout << ans << endl;
}


signed main(){
    int t; cin >> t;
    while(t--){
        fn();
    }
}