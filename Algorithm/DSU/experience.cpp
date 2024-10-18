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

class DSU{
    public:
    vector<int> p;
    vector<int> siz;
    vector<int> sum;

    DSU(int sz){

        p.resize(sz+1);
        siz.resize(sz+1,1);
        sum.resize(sz+1,0);

        for(int i=0 ; i < sz+1 ; i++){
            p[i]=i;
            sum[i]=0;
        }

    }
    int parent(int i){
        if( p[i] == i ) return i;
        return p[i] = parent(p[i]);          // is logic se is line ki wajah se wrong ho rha hai .....
    }
    void unite(int i , int j){
        i = parent(i);
        j = parent(j);
        if(i == j) return;
        
        if(siz[i] > siz[j]  || (siz[i] == siz[j] && sum[i] >= sum[j]) ){
            siz[i] += siz[j];
            p[j] = i;
            sum[j] -= sum[i];
        }else{
            p[i] = j;
            siz[j] += siz[i];
            sum[i] -= sum[j];
        }
    }

    void add(int x,int v){
        sum[parent(x)] += v;
    }
    int get(int x){
        if(parent(x) == x) return sum[x]; 
        int value = sum[x];
        value += sum[parent(x)];
        return value;
    }

};

signed main(){
    ios::sync_with_stdio(false); // Fast I/O
    cin.tie(0); // Untie cin from cout

    int n,m;
    cin >> n >> m;
    DSU d(n);
    l(i,0,m){
        string s;
        cin>>s;
        
        if( s == "add"){
            int a,b;
            cin>>a>>b;
            d.add(a,b);
        }else if( s == "join" ){
            int a,b;
            cin>>a>>b;
            d.unite(a,b);
        }
        else{
            int a;
            cin >> a;
            cout << d.get(a) << endl;
        }

    }
}
