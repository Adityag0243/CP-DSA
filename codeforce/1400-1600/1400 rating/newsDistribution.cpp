#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>

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

vector<int> father;
vector<int> sz;

void init(int n){
    father.resize(n+2);
    sz.resize(n+2);
    l(i,1,1+n) father[i] = i;
    l(i,1,1+n) sz[i] = 1;
}

int fatherNode(int a){
    if( father[a] != a){
        father[a] = fatherNode(father[a]);
    }
    return father[a];
}

void unite(int a, int b){
    
    a = fatherNode(a);
    b = fatherNode(b);
    if( a == b) return;

    if( sz[b] > sz[a]) swap(a,b);

    sz[a] += sz[b];  
    father[b] = a;
}

signed main(){
    
    int n,m; cin >> n >> m;
    init(n);
    

    while( m-- ){
        int k; cin >> k;
        
        vi vk(k);
        int first = -1;
        
        l(i,0,k){
            int a; cin >> a;
            if( i != 0){
                unite(first, a);
            }else first = a;
        }
    }

    for(int i = 1; i<=n ; i++){
        cout << sz[fatherNode(i)] << " ";
    }
    
    return 0;
}