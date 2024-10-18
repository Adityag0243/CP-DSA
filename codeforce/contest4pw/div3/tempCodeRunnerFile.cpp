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



// class from chatgpt

class SegmentTree {
public:
    SegmentTree(const vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); 
        build(arr, 0, 0, n - 1);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }

private:
    vector<int> tree;
    int n;

    void build(const vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            build(arr, 2 * node + 1, start, mid);
            build(arr, 2 * node + 2, mid + 1, end);
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int left, int right) {
        if (right < start || end < left) {
            return INT_MIN; 
        }
        if (left <= start && end <= right) {
            return tree[node];
        }
      
        int mid = (start + end) / 2;
        int max_left = query(2 * node + 1, start, mid, left, right);
        int max_right = query(2 * node + 2, mid + 1, end, left, right);
        return max(max_left, max_right);
    }
};


int n;   // size of array

int binary_(int pos , int t , SegmentTree &seg){

    int low  = pos;
    int high = n-2;
	int ans = pos-1;

    while(low <= high){
        int mid = (high + low)/2;
        if( seg.query(pos,mid) <= t){
            ans = mid;
            low = mid+1;
        }else high = mid-1;
    }
    return ans;
}



signed main() {


    cin >> n;
    vector<int> v(n);
    l(i,0,n) cin >> v[i];

    vector<int> diff;

    l(i,0,n-1){
        diff.pb(abs(v[i+1]-v[i]));
    }
	diff.pb(0);
    SegmentTree segTree(diff);


    int q;
    cin >> q;
    while(q--){
		
        int a,b,c;
        cin>> a >> b >> c;
		if(n==1 and a==2){
			cout<<1<<endl;
			continue;
		}
        if( a == 2){
            cout << binary_(b-1,c,segTree) + 2 << endl;
        }else{
            v[b-1] = c;
            if( b == 1){
                segTree.update( 0 , abs(v[1]-v[0]) );
            }else if( b == n){
                segTree.update( n-2 , abs(v[n-1]-v[n-2]) );
            }else{
                segTree.update( b-2 , abs(v[b-1]-v[b-2]) );
                segTree.update( b-1 , abs(v[b]-v[b-1]) );
            }
        }

    }
    

}













