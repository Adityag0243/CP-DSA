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

signed main(){
    int n,m;
    cin >> n >> m;
    vi b(n);
    vi g(m);
    l(i,0,n) cin>>b[i];
    l(i,0,m) cin>>g[i];
    srt(g);
    srt(b);
   
   if(g[0] < b[n-1]){
    cout<<-1<<endl;
    return 0;
   }

    int sum = 0;
    l(i,0,n-1) sum += b[i]; 
    sum *= m;

    sum += b[n-1];     // insuring atleast b[n-1] is present
    l(i,1,m) sum += g[i];


    if( g[0] > b[n-1]){
        if(n-2 >= 0) sum += (g[0]-b[n-2]);
        else sum = -1;        // test case n=1 m=1 b=7 g=8   or n=1 m=2 b=7 g=8,8
    }
    cout<<sum<<endl;

}