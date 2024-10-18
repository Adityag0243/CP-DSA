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

int fn(vector<int> &v, int t, int p1, int p2){
    // cout <<"for time p1 and p2: "<< t<<" " << p1 <<" "<<p2 << endl;
    
    if(t == n || p1 == p2){
        return t*v[p1];
    }
    return max( t*v[p1]+fn(v,t+1 , p1+1 , p2) , t*v[p2] + fn(v,t+1 , p1 , p2-1));
}



signed main(){
    
    cin >> n;
    vi v(n);
    l(i,0,n) cin >> v[i];
    cout << fn(v,1,0,n-1);
        
}