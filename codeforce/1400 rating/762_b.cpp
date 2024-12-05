#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
#define int             long long
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
    int a,b,c;
    cin >> a >> b >> c;

    int m;
    cin>>m;
    vi usb;
    vi ps2;
    l(i,0,m){
        int price;
        cin >> price;
        string s;
        cin >> s;
        if(s[0] == 'U') usb.pb(price);
        else ps2.pb(price);
    }
    srt(usb);
    srt(ps2);

    int cnt = 0;
    int zero = 0;
    int x = min(a,(int)usb.size());   // only usb
    cnt += x;

    int y = min(b,(int)ps2.size());   // only ps2 
    cnt += y;

    int sum = 0;
    l(i,0,x){
        sum += usb[i];
    }

    l(i,0,y){
        sum += ps2[i];
    }

    // now c more require and can take from any vector
    vi v;
    l(i,x,usb.size()) v.pb(usb[i]);
    l(i,y,ps2.size()) v.pb(ps2[i]);
    srt(v);
    c = min(c,(int)v.size());
    cnt += c;
    l(i,0,c){
        sum+=v[i];
    }

    cout<<cnt<<" "<<sum;
}