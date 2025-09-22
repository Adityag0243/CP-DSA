#include <bits/stdc++.h>
using namespace std;
#define all(arr)        arr.begin(), arr.end()
#define vi              vector<int>
#define vvi             vector<vi>
// #define int             int64_t
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

vector<pair<int,int>> xs;
vector<pair<int,int>> ys;





signed main(){
    int a,b; cin >> a >> b;
    int x,y; cin >> x >> y;

    if((x == 0 && y ==0) || (x == 0 && y == b) || (x == a && y == 0) || (x == a && y == b)){
        cout << 0;
        return 0;
    }

    if(x == 0) xs.pb({0,0});
    else if(x == a) xs.pb({a,a});
    else{
        int f = 0, l = a;
        xs.pb({r,l});

        while(  ((f+l) % 2 == 0)  && (f+l)/2 != x){
            if( (f+l)/2 > x ){
                l = (f+l)/2;
            }else{
                f = (f+l)/2;
            }
        }

        if((f+l)% 2==0 && (f+l)/2 == x){
            xs.pb({f,l});
        }else{
            cout << -1 << endl;
            return 0;
        }
    }


    if( y == 0) ys.pb({0,0});
    else if( y == b) ys.pb({b,b});
    else{
        int r = 0, l = b;
        ys.pb({r,l});

        while(  ((f+l) % 2 == 0)  && (f+l)/2 != y){
            if( (f+l)/2 > y ){
                l = (f+l)/2;
            }else{
                f = (f+l)/2;
            }
        }

        if((f+l)% 2==0 && (f+l)/2 == y){
            ys.pb({f,l});
        }else{
            cout << -1 << endl;
            return 0;
        }

    }
    int xz = xs.size(), yz = ys.size();

    cout << max(xz,yz) << endl;
    if( xz >= yz ){
        for(int i = 0; i<(xz-yz); i++ ){
            cout << xs[i].first << " " << 0 << " " << xs[i].second << " " << 0 << endl;
        }
        for(int i = (xz-yz), j = 0; i <xz; i++,j++){
            cout << xs[i].first << " " << ys[j].first << " " << xs[i].second << " " << ys[j].second << endl;
        }
    }else{
        for(int i = 0; i<(yz-xz); i++ ){
            cout << 0 << " "<< ys[i].first << 0 << " " << ys[i].second << endl;
        }
        for(int j = (xz-yz), i = 0; i < xz; i++,j++){
            cout << xs[i].first << " " << ys[j].first << " " << xs[i].second << " " << ys[j].second << endl;
        }
    }


    
    
    

    return 0;
}