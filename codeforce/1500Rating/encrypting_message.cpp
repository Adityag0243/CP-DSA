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
    int n,m,c;
    cin >> n >> m >>c;

    vector<int> a(n),b(m);
    l(i,0,n){
        cin>>a[i];
        a[i]%=c;
    }
    l(i,0,m){
        cin>>b[i];
        b[i]%=c;
    }

    vector<int> pre(m),suf(m);
    pre[0]   = b[0];
    suf[m-1] = b[m-1];

    l(i,1,m)    pre[i] = (pre[i-1] + b[i]);
    rl(i,0,m-1) suf[i] = (suf[i+1] + b[i]);


    l(i,0,n){
        if(i<m-1)   cout << (a[i] + pre[i])%c<<" ";
        else if(i>n-m) cout<< (a[i] + suf[m-n+i])%c<<" ";
        else cout<< (a[i]+pre[m-1])%c<<" ";
    }


}